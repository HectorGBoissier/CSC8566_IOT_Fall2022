# Raspeberry Pi Setup
In this tutorial you will install the DietPi operating system on your Raspeberry Pi connected via WiFi router

## Required Hardware
You will need the following equipment to complete the setup:
- Laptop or desktop
- Raspberry PI 3 B+ or 4
- Micro SD card between 8GB and 32GB
- WiFi router

## Hardware used in this tutorial
- **Laptop**: Lenovo ideapad 520-15IKB. 16GB RAM, 256GB SSD, i7 8th Gen, Windows 10 21H2.
- **Router**: GL.iNet GL-MT300N-V2(Mango). 300Mbps Wireless Router.
- **Device**: RaspberryPi 4. Model B with 2GB RAM.
- **Memory Card**: SanDisk Ultra 16GB micro SD.

Before you begin, you'll need to have a previously configured WiFi router to create a local portable network for your Raspberry Pi.
If you need help setting up your personal travel router, you can follow the [Router Setup Tutorial](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/tree/main/Setup_Router_Tutorial).

## Required Software
- **BreeZip Archiver** extractor to unzip the Pi OS files. https://www.breezip.com/
- **BalenaEtcher** to flash the SD card with the Pi image. https://www.balena.io/etcher/
- Download the **DietPi** image for you RaspberryPi. https://dietpi.com/#download - I am using ARMv8 64-bit image for my RPI 4. You can download this version from https://dietpi.com/downloads/images/DietPi_RPi-ARMv8-Bullseye.7z

## Setup Steps
1.Flash SD card
- Once you have downloaded the DietPi image, extract the files in a directory on your local computer.
- Open balenaEtcher. You will see three different items on the main screen. The leftmost item will select the image files, the middle one to select the target card, and the last item to confirm and flash the SD card. 
- Insert your microSD card into your laptop. If you don't have a port for your card on your laptop, you likely need a microSD to USB adapter. 
- The SD card should come up automatically under the targeted card in balenaEtcher if inserted correctly.
- Select **Flash from file** and navigate to the location where you extracted the DietPi Disc Image File.
- Press Flash and wait for the process to finish. Use your computer admin credentials if prompted.
 

2.Configure DietPi

Now you will configure the boot image files that were flashed to the SD card. Copy dietpi.txt and dietpi-wifi.txt to a temporary directory so you can edit them safely. Make sure to save an additional copy if case you need to retrieve the originals.
- Edit *dietpi-wifi.txt* by typing your router's SSID and password as shown in the following variables. Do not delete the '' punctuation marks.
   ```
   aWIFI_SSID[0]='Your router's SSID'
   aWIFI_KEY[0]='The ssid password'
   ```
- Edit *dietpi.txt* to change the configuration to the following values:
   ```
   AUTO_SETUP_LOCALE=en_US.UTF-8
   AUTO_SETUP_KEYBOARD_LAYOUT=us
   AUTO_SETUP_TIMEZONE=America/New_York
   AUTO_SETUP_NET_ETHERNET_ENABLED=0
   AUTO_SETUP_NET_WIFI_ENABLED=1
   AUTO_SETUP_NET_WIFI_COUNTRY_CODE=US
   AUTO_SETUP_DHCP_TO_STATIC=1
   AUTO_SETUP_NET_HOSTNAME=DietPi_{YOUR_INITIALS}
   AUTO_SETUP_HEADLESS=1
   AUTO_SETUP_AUTOSTART_TARGET_INDEX=1
   SURVEY_OPTED_IN=0
   CONFIG_SERIAL_CONSOLE_ENABLE=1
   ```
Note that these lines do not appear one after another in the file. You will need to find each variable in the document and change the corresponding value.
Remember to replace {YOUR_INITIALS} in the AUTO_SETUP_NET_HOSTNAME variable. In my case, I changed the value to *DietPi_HGB*.

- Save the documents that you have edited on a temporary directory and copy them back to their original location on your SD card. 
- Make sure to safely eject your SD card from your laptop. In the File Explorer window, you can do this by right-clicking the SD card and selecting *Eject*.


3.Install SD card and boot up the RPI
- Insert your microSD card in the Raspberry Pi. The microSD slot is located on the bottom side of the RPI 4.
- Power on your Raspberry Pi. I used my laptop for power by using a USB to USB-C cable. Here is my personal setup:

![Personal Hardware Setup](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/RPI_setup_tutorial/RaspberryPi_Setup/Images/Hardware-setup.jpg)

- Here you will see a red light and a flashing green light come up on the board. Wait until the green light stops flashing. I only had to wait a couple of minutes but it could take up to 10 depending on your local network load.

4.Login to the RPI
- Find IP address of your Raspberry Pi by going to your router's Admin website (http://192.168.8.1 For GL.iNet router). If your device has booted up and the *dietpi* configuration files were edited correctly, you should see the **DietPi** on your **CLIENTS** page.

![Admin Website Clients](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/RPI_setup_tutorial/RaspberryPi_Setup/Images/Admin-clients.JPG)

- Use SSH to login to your Pi.
You can do this from your Command Prompt using the following command. When prompt to enter the password, use the default password *dietpi*.
   ```
   ssh root@IpAddress
   password: dietpi
   ```
Here I received a notification saying that "The authenticity of host 'IpAdress' can't be established." Type yes to continue to establish the SSH connection.

**Note**: If you are using a GL.iNet GL-MT300N-V2(Mango) you may encounter issues connecting to the DNS server when connected to the Villanova University's WiFi.
This will result in the automatic updates after the first logon to fail. See the following error that I encountered as a result of VUGuest blocking ping traffic:

![Connection Error](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/RPI_setup_tutorial/RaspberryPi_Setup/Images/DNS-error.jpg)
If you encounter this error, I recommended using your phone hotspot or the tethering method to setup the router connection. 
To learn how to setup **Tethering** on your router, please refer to the following tutorial [Optional Router Setup](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/RPI_setup_tutorial/Setup_Router_Tutorial/OptionalSetup.md)

If your RaspberryPi sucessfully finishes booting up and running the initial updates, you will see the following command screen, where you can type commands from the root account:

![Succesful Connection](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/RPI_setup_tutorial/RaspberryPi_Setup/Images/DietPi-initial-updates-finished.JPG)


5.Finish configuration of DietPi

- DietPi has two accounts by default "**root**" and "**dietpi**". Please make sure to change the global software password (or root password) from the default *dietpi* to a password of your choice. You can also change the default unix user password, which is also *dietpi*.
- The RPI will automatically prompt you to update these passwords after the initial updates. 
- If you are not automatically prompted due to connection issues or you skip this step, you can always change them later by using the *dietPi-config* command to access the configuration menu. There you can press **Security Options** to update both passwords at any time.

6.Further Software Installs

To continue installing platform software, please refer to the next tutorial [IOT Plaform Install](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/RPI_setup_tutorial/RaspberryPi_Setup/IOT_Platform_Install.md)

## References
Readme.md by Professor Schragger: https://github.com/pschragger/IOT_Tutorials_for_VU/tree/main/RPI_BOOT_WIFI_tutorial