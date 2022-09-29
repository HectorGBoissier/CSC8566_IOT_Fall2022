# DHT11 Setup with Arduino IDE & ESP32 

## Required Hardware

- Laptop or Desktop
- ESP32 Wrover
- GPIO Extension Board
- Breadboard
- 4x M/M Jumpers
- 10kOhm Resistor 
- DHT11

## Initial Setup and Requirements

For this first experiment, I followed the instructions in **Chapter 24 Hygrothermograph DHT11** of the Freenove *C_Tutorial* that I downloaded from [Freenove_Ultimate_Starter_Kit_for_ESP32](https://github.com/Freenove/Freenove_Ultimate_Starter_Kit_for_ESP32). 
The experiment setup was done using the hardware components provided in the Freenove Starter Kit. The only thing you need besides the kit is your own laptop with the Arduino IDE installed. 

The *C_Tutorial* file also contains instructions on how to download, install, and configure the Arduino IDE with detailed steps on the **Preface** Chapter.
You may also need to install the CH340 driver on your laptop for the USB communication with the ESP32 Wrover Module. Instruction on how to install this driver can also be found in the Freenove tutorial.

## Setup Steps

First, wire the circuit components as shown in the following circuit diagram given in the tutorial:

![Circuit Diagram](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/Analog_Sensor_Tutorial/Analog_Sensor_Tutorial/images/1-Circuit%20Diagram.JPG)

Also, use the USB cable from the Starter Kit to connect the ESP32 Wrover Module directly into the USB port on your computer. 
This was the resulting circuit on my ESP32 Wrover Board:

![Circuit Picture](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/Analog_Sensor_Tutorial/Analog_Sensor_Tutorial/images/2-Circuit%20Diagram.jpg)

Install the **DHT sensor library for ESPx** on the Arduino IDE by searching "DHT esp" in the Library Manager. Select *Install*

![Library](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/Analog_Sensor_Tutorial/Analog_Sensor_Tutorial/images/0-Install%20library.JPG)

Copy and paste the sample code provided in the C_Tutorial: 

    ```
#include "DHTesp.h"

DHTesp dht; //Define the DHT object
int dhtPin = 13;//Define the dht pin

void setup() {
  dht.setup(dhtPin, DHTesp::DHT11);//Initialize the dht pin and dht object
  Serial.begin(115200); //Set the baud rate to 115200
}
void loop() {
  flag:TempAndHumidity newValues = dht.getTempAndHumidity();//Get the Temperature and humidity
  if (dht.getStatus() != 0) { //Judge if the correct value is read
    goto flag; //If there is an error, go back to the flag and re-read the data
  }
  Serial.println(" Temperature:" + String(newValues.temperature) +
  " Humidity:" + String(newValues.humidity));
  delay(2000);
}
    ```

Note that since I wanted my measurements in Farenheit, I added the conversion formula on the output as shown here:
 
    ```
  Serial.println(" Temperature:" + String((newValues.temperature)*9/5+32) +
  " Humidity:" + String(newValues.humidity));
  delay(2000);
}
    ```

Make sure to check under **Tools** that the selected *Board:* is **ESP32 Wrover Module**. The **Upload Speed** has to be set to 115200 and the **USB Port** used by the ESP32 has to be selected as well. In my case, the USB port was *COM3*. If you are unsure, you can check on the *Device Manager* on your PC.

Finally, click on the **Upload** Button to compile and flash the code into the ESP32 board. To see the output of the Temperature and Humidity measurements you will need to open the **Serial Monitor** window. The icon to open the window is located on the top-right corner of the Arduino IDE, and it looks like a magnifying glass.

Humidity and Temperature Sensor code output:

![Serial Monitor](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/Analog_Sensor_Tutorial/Analog_Sensor_Tutorial/images/3-Arduino%20Running%20Output.JPG)

If you would like to see a video of the full setup and code running, please check my post on the Internet of Things Fall 2022 YellowDig Community: [Blopg Post](https://computing-sciences.yellowdig.app/community/62e2eacc-366d-319c-a96d-cf1e0b1d27ef?postId=47424135932456466)