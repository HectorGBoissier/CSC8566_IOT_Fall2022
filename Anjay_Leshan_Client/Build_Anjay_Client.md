# Build LWM2M client on RPI for ESP32

This tutorial provides instructions on how to build a LWM2M client.
The open-source Anjay library and esp-idf will be used to setup and register your ESP32 board on a Leshan server.

## Requirements

It is assumed that the user has already completed the initial setup to start their own Leshan server. Instructions on how to install the required software and how to start the Leshan server are included in the following tutorial: 

[LWM2M Setup and Testing](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/tree/main/LWM2M)

You need an ESP32 development board. In this tutorial, the client was built for the ESP32-Wrover from the [Freenove Starter Kit](https://github.com/Freenove/Freenove_Ultimate_Starter_Kit_for_ESP32). 

Follow the tutorial [Building an LWM2M clients on RPI for ESP32](https://github.com/pschragger/IOT_Tutorials_for_VU/tree/main/RPI_BUILD_LWM2M_DEVICE) by Professor Schragger until the Section **Build the ANJAY client**.
The steps will show you how to install and build the Anjay libraries on your Raspberry Pi. 

## Start the Leshan Server

On your Raspberry Pi, go to your leshan directory and use the following command to start the server:

```
cd projects/leshan
java -jar leshan-server-demo/target/leshan-server-demo-*-SNAPSHOT-jar-with-dependencies.jar &
```
You should be able to connect to the Leshan demo UI by going to http://RPI_IPaddress:8080. as shown in the following image:

![Leshan Server Started](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/Anjay-leshan/Anjay_Leshan_Client/Images/1-Leshan_server_started.JPG)

## Build Anjay Client

Now you can continue typing the commands required to build the anjay client for the ESP32 board.

Go to the anajay-esp32-client directory and type the following commands to setup the local environment

```
cd ~/projects/Anjay-esp32-client
. $HOME/esp/esp-idf/export.sh
idf.py set-target esp32 
```

Setup your device requirements by using the command
```
idf.py menuconfig
```
This will take you to the following screen:

![Menu Config](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/Anjay-leshan/Anjay_Leshan_Client/Images/2-Menu-config.JPG)

Navigate to "Component config --->", and then all the way down to "anjay-esp32-client --->"

![Anjay Config](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/Anjay-leshan/Anjay_Leshan_Client/Images/3-anjay-config.JPG)

Now change the following settings:

- Under "Choose targeted development board", select "ESP-Wrover-KIT"
- Under "Client options", change the Server URI to "coap://RPI_IPaddress:5683", in my case he URI was coap://192.168.8.232:5683. Make sure to use *coap* instead of *coaps*.
- Leave socket as "UDP" but change the security mode to "Non-secure connection"
- Under "Connection configuration", type your WIFI router SSID and password to allow your ESP32 to connect to your router.

Type Q and then Y to quit and save your configuration. 

Use the ```idf.py build``` command to build the code for the device.

Make sure your ESP32 board is plugged into one of your Raspberry Pi USB ports as shown in the following image:

![Hardware Setup](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/Anjay-leshan/Anjay_Leshan_Client/Images/4-hardware-setup.jpg)

To find the port number being used by the board, use the command ```ls -l /dev/ttyUSB*```. In my case, it returned "crw-rw---- 1 root dialout 188, 0 Oct  5 23:23 /dev/ttyUSB0", so the port number is 0. Use the following command and "idf.py -p port_number flash" to flash the code into your ESP32:
```
sudo chmod 666 /dev/ttyUSB0
idf.py -p 0 flash
```

Open your leshan server at http://RPI_IPaddress:8080 to check the registration of your ESP32. The following pictures show the Leshan UI and the Device information page after selecting the registered #anjay-esp32-client#:

![Registered Client](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/Anjay-leshan/Anjay_Leshan_Client/Images/5-anjay-registered-client.JPG)

![Client Information](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/Anjay-leshan/Anjay_Leshan_Client/Images/6-client-device-page.JPG)

Here you can see the available options for **Light Control** & **Push Button**. Continue to the [Analog Experiment using Anjay client code](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/Anjay-leshan/Anjay_Leshan_Client/Anjay_Client_Experiment.md) tutorial to experiment with these two options. 

