# Build LWM2M client on RPI for ESP32

This tutorial provides instructions on how to build a LWM2M client.
The open-source Anjay library and esp-idf will be used to setup and register your ESP32 board on a Leshan server.

## Requirements

It is assumed that the user has already completed the initial setup to start their own Leshan server. Instructions on how to install the required software and how to start the Leshan server are included in the following tutorial: 

[LWM2M Setup and Testing](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/tree/main/LWM2M)

The user will also need an ESP32 development board. In this tutorial, the client was build for the ESP32-Wrover board from the [Freenove Starter Kit](https://github.com/Freenove/Freenove_Ultimate_Starter_Kit_for_ESP32). 

## Setup

