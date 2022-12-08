#include <WiFi.h>
#include <MQTTPubSubClient.h>
#include <Keypad.h>
#include <ESP32Servo.h>

//Wifi
const char* ssid = "IOT_FALL_2022_WIFI_HGB";
const char* pass = "303cclavado";

//MQTT Pub/Sub
WiFiClient client;
MQTTPubSubClient mqtt;

//Motor
char doorLockID = '1';

//Message
char message[6];

//Built-in LED
int ledBuiltin = 2;
int ledERROR = 4;

//Keypad
char keys[4][4] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
byte rowPins[4] = {14, 27, 26, 25}; 
byte colPins[4] = {13, 21, 22, 23}; 

Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

//Servo Motor
Servo myservo;
int servoPin = 19;

//Initially unlocked
bool lockStatus = false;

//Initial Setup
void setup() {

  message[0] = doorLockID;
  message[1] = '/';

  pinMode(ledBuiltin, OUTPUT);
  pinMode(ledERROR, OUTPUT);

  myservo.setPeriodHertz(50); 
  myservo.attach(servoPin, 500, 2500);
  myservo.write(0);

  Serial.begin(115200);

  WiFi.begin(ssid, pass);

  //Connecting to Wifi
  Serial.print("connecting to wifi...");
  while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(1000);
  }
  Serial.println(" connected!");

  //Connecting to MQTT Host
  Serial.print("connecting to host...");
  while (!client.connect("192.168.8.232", 1883)) {
      Serial.print(".");
      delay(1000);
  }
  Serial.println(" connected!");

  // Initialize MQTT client
  mqtt.begin(client);

  //Connecting client to MQTT Broker
  Serial.print("connecting to mqtt broker...");
  while (!mqtt.connect("arduino", "public", "public")) {
      Serial.print(".");
      delay(1000);
  }
  Serial.println(" connected!");

  // Subscribe topic /actuator/servo
  // If User input is Right, Door Lock activates and sends updated servo value to update the DB
  mqtt.subscribe("/actuator/servo", [](const String& payload, const size_t size) {
    Serial.println("mqtt received: " + payload);
    if (payload == "RIGHT"){
      if (!lockStatus){
        Serial.println("Locking door...");
        myservo.write(90);
        lockStatus = true;
        digitalWrite(ledBuiltin, HIGH);
        mqtt.publish("/actuator/servo/value", "90");
      }
      else if (lockStatus) {
        Serial.println("Unlocking door...");
        myservo.write(0); 
        lockStatus = false;
        digitalWrite(ledBuiltin, LOW);
        mqtt.publish("/actuator/servo/value", "0");
      }
    }
    else if(payload == "WRONG"){
      Serial.println("passWord error! Recording failed attempt...");
      digitalWrite(ledERROR, HIGH);
      delay(1000);                      
      digitalWrite(ledERROR, LOW);
    }
  });

}

void loop() {

  mqtt.update();

  static char keyIn[4]; 
  static byte keyInNum = 0; 
  char keyPressed = myKeypad.getKey();

  // User Input
  if (keyPressed) {

    keyIn[keyInNum++] = keyPressed;

    if (keyInNum == 4) {

      for (int i = 0; i < 4; i++) { 
        message[i+2] = keyIn[i];
      }
      
      // Publishes message: "doorLockID/keyIn"
      mqtt.publish("/sensor/keypad", message);
      
      // Reset Input Characters
      keyInNum = 0; 
    }
  }
}