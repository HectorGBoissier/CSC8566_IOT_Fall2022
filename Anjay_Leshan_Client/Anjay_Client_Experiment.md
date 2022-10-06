# Anjay Client Experiments for ESP32

This is the continuation of the [Build LWM2M client on RPI for ESP32](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/Anjay-leshan/Anjay_Leshan_Client/Build_Anjay_Client.md) tutorial. 
Now that you are able to successfully register your ESP32 board on your Leshan server, you can experiment with the LwM2M Objects provided in the [Anjay client code](https://github.com/AVSystem/Anjay-esp32-client) by AVSystem.
In this experiment, the client was build for the ESP32-Wrover and the hardware equipment from the [Freenove Starter Kit](https://github.com/Freenove/Freenove_Ultimate_Starter_Kit_for_ESP32). 

## Light Control

The first Anjay Client object experiment is the **Light control** (/3311) available for *ESP-WROVER-KIT* boards. 
You do not need to make any changes to the component configuration for the build that we set up in the previous tutorial.

Follow the instructions provided in **Chapter 1 LED** of the [Freenove C_Tutorial](https://github.com/Freenove/Freenove_Ultimate_Starter_Kit_for_ESP32/blob/master/C/C_Tutorial.pdf) to build the LED circuit on the breadboard. See the following diagram and my LED circuit for reference:

![Diagram Picture]()

![Circuit Picture]()

I recommend wiring the circuit before you connect the ESP32 to the Raspberry Pi and before you flash the anjay code to register the client. 

Note that you can also try this control application without having to setup the external LED circuit. The changes made to the light on the Anjay client will be shown by the Blue LED light on the ESP-Wrover board itself. If you do the full circuit setup, both LED lights will respond to the Write commands sent to the client.  

Now that the circuit is fully set up and the client is registered on the leshan server, you can begin writing commands on the anjay client object.
Select the registered **anjay-esp32-client** object and click on **Light Control**. This panel has all the possible variables that can be modified to control the light, but we will focus on the **ON/OFF** and the **Dimmer** values.

Select read **R** on the Dimmer value. The possible dimmer values range from 0-100, and you will notice it is set to 0 by default. Change this value to 100 using the write **W** command. 
Next, read the ON/OFF value. Here "false" is off and "true" turns the LED lights on. Change the value to "true" to see the LED light turn on. 
Now you can experiment and see the effects of change these settings. In particular, try changing the Dimmer value to 10 and then to a high number such as 90, so you can easily observe the change in intensity.
Please see my blog post on the YellowDig IoT Community where I included two videos on this experiment. 

![Circuit LED On]()

## Push Button 

The second Anjay Client object available for *ESP-WROVER-KIT* boards is the **Push Button** (/3347).
The same component configuration will be used for this experiment.

Follow the instructions provided in **Chapter 2 LED & Button** of the [Freenove C_Tutorial](https://github.com/Freenove/Freenove_Ultimate_Starter_Kit_for_ESP32/blob/master/C/C_Tutorial.pdf) to build the LED circuit on the breadboard. To experiment with the Push Button object, you do not need to wire the LED section of the circuit. 
See the following diagram and image of my button circuit for reference:

![Diagram Picture 2]()

![Circuit Picture 2]()

Select the registered **anjay-esp32-client** object and click on **Push Button**. The value that we will focus on is the **Digital Input Counter**.
Select Observe* on the top left of the panel first, then push the button on the circuit a couple of times. Wait a couple seconds and then select Read on the input counter. You shoul see the counter increase as shown in the following picture:

![Input counter]()

The Anjay ESP32 client code also allows to change the component configuration to an Unknown Board, allowing to use different pin numbers on the board and use different color LED lights. 
For further information, please check the Anjay Client code in the AVSystem repository. This repo and the tutorial by Professor Schragger were used as a reference to create this tutorial.


