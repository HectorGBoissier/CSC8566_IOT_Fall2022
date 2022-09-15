# Raspeberry Pi Setup
In this tutorial you will install DietPi operating system on your Raspeberry Pi using your WiFi router

## Prerequisites
You will need the following equipment to complete the setup:
- Laptop or desktop
- Raspberry PI 3 B+ or 4
- Micro SD card between 8GB and 32GB
- WiFi router

## Hardware used for the setup
- Laptop: Lenovo ideapad 520-15IKB. 16GB RAM, 256GB SSD, i7 8th Gen, Windows 10 21H2.
- Router: GL.iNet GL-MT300N-V2(Mango). 300Mbps Wireless Router.
- Device: RaspberryPi 4. Model B with 2GB RAM.
- Memory Card: SanDisk Ultra 16GB micro SD.

Before you begin this tutorial, you'll need to have a previously configured WiFi router to create a local portable network for your Raspberry Pi.
If you need help setting up your personal travel router, you can follow the [Router Setup Tutorial](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/tree/main/Setup_Router_Tutorial).

## Required Software
- **BreeZip Archiver** extractor to unzip the Pi OS files. https://www.breezip.com/
- **BalenaEtcher** to flash the SD card with the Pi image. https://www.balena.io/etcher/
- Download the **DietPi** image for you RaspberryPi. https://dietpi.com/#download - I am using ARMv8 64-bit image for my RPI 4. You can download this version from https://dietpi.com/downloads/images/DietPi_RPi-ARMv8-Bullseye.7z

## Setup Steps
1. Flash SD card
- Once you have downloaded the DietPi image, extract the files in a directory on your local computer.
- Open balenaEtcher. You will see three different items on the main screen. The leftmost item will select the image files, the middle one to select the target card, and the last item to confirm and flash the SD card. 
- Insert your microSD card into your laptop. If you don't have a port for your card on your laptop, you likely need a microSD to USB adapter. 
- The SD card should come up automatically under the targeted card in balenaEtcher if inserted correctly.
- Select **Flash from file** and navigate to the location where you extracted the DietPi Disc Image File.
- Press Flash and wait for the process to finish. Use your computer admin credentials if prompted.
 

2. Configure DietPi
Now you will configure the boot image files that were flashed to the SD card. Copy dietpi.txt and dietpi-wifi.txt to a temporary directory so you can edit them safely. Make sure to save an additional copy if case you need to retrieve the originals.
- Edit dietpi-wifi.txt

- Edit dietpi.txt 


3. Install SD card and boot up the RPI


4. Login to the RPI


## References
Readme.md by Professor Schragger: https://github.com/pschragger/IOT_Tutorials_for_VU/tree/main/RPI_BOOT_WIFI_tutorial