# LWM2M Setup and Testing

## Motivation

The purpose of this directory is to share my experience setting up and testing a LWM2M server and client on the Raspberry Pi.

The tutorial provided in the **Device Management Install Tutorial** REAME.md file by Professor Schragger was used to setup the Leshan server and client:

https://github.com/pschragger/IOT_Tutorials_for_VU/blob/main/RPI_DEVICE_MANAGEMENT_INSTALL_tutorial/README.md


## Setup

The tutorial steps were followed to download and install the software on DietPi. Beside unstable connection and slow download speed, no major issues were encountered.

- Git Install
Steps followed as tutorial. Verified install with the command: 
    ```
    git --version
    ```

![Git Sucessful Install](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/LWM2M/LWM2M/Images/4-git-version-installed-1.JPG)

- Java JDK Install
Steps followed as tutorial.
Verified install with the command:  
    ```
    java --version
    ```

![Java JDK Sucessful Install](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/LWM2M/LWM2M/Images/7-java-jdk-version-installed-2.JPG)

Here I skipped ahead in the tutorial before downloading maven, as I wanted to ensure that java was all setup first. I followed the instructions at the end of section 3 to create a **JAVA_HOME** environment variable:

![Java JDK Environment Variable](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/LWM2M/LWM2M/Images/8-java-home-environment-install-3.JPG)

- Maven Install

The steps in the tutorial to download and unpack the latest maven tarball were followed as indicated. When setting up the environment variable, I went straight to step *vii* from step *iv* since I downloaded the same maven version in the same download directory.
Here is the result of testing the maven installation with 
    ```
    mvn -v
    ```
 command:

![Maven Environment Variable](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/LWM2M/LWM2M/Images/12-maven-installation-test-4.JPG)

- Leshan Install

The steps provided in section 4 of the tutorial were followed and the installation process took 23 minutes. 

![Leshan Successful Build](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/LWM2M/LWM2M/Images/14-leshan-build-success-5.JPG)

## Testing

The tutorial by Professor Schragger also includes a few steps to test the leshan server. By going to the leshan directory and using the command 
    ```
    java -jar leshan-server-demo/target/leshan-server-demo-*-SNAPSHOT-jar-with-dependencies.jar &
    ```
 you will start the server.
I then connected to the Leshan demo UI by going to http://192.168.8.232:8080, where 192.168.8.232 is my Raspberry Pi's IP address. Since you have only started the server, you will not see any clients in the UI yet:

![Leshan Server Start](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/LWM2M/LWM2M/Images/15-leshan-server-started-6.JPG)

After starting the server, you can then run the leshan client to register your DietPi host on the lwm2m server by using the command 
    ```
    java -jar leshan-client-demo/target/leshan-client-demo-*-SNAPSHOT-jar-with-dependencies.jar
    ```
. This will result on you RPI being registered as a Temperature client end point, which updates every minute:

![Leshan Client Registration](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/LWM2M/LWM2M/Images/16-leshan-pi-registration-7.JPG)

Selecting the DietPi client will give you the temperature readings:

![DietPi Temperature](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/LWM2M/LWM2M/Images/20-leshan-server-device-temperature-8.JPG)

You can also check the server page to see the server active url, public keys, and certifcate information:

![Leshan Server Info 1](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/LWM2M/LWM2M/Images/17-server-information-9.JPG)


![Leshan Server Info 2](https://github.com/HectorGBoissier/CSC8566_IOT_Fall2022/blob/LWM2M/LWM2M/Images/18-server-information-10.JPG)

