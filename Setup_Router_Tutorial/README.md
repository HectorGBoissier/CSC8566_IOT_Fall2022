# Router Setup 

## Tutorial for GL.iNet GL-MT300N-V2(Mango) 

- Power on your router by pluging in the power cable.
The USB connection of this cable can be plugged in to your personal laptop to power the router. 
- Look up the specific SSID of your device **GL-MT300N-V2-xxx**, which is printed on the bottom of the router.
- Check out the available Wi-Fi networks and connect to the one with your router's SSID. 
You will first need to use the default password **goodlife**.
- Open your browser and visit **_htpp://192.168.8.1_**.
Here you will first need to setup the admin password. This password will be used to access the GL.iNet Admin Panel.
- Go to the **Wireless** tab on the left of the panel to change the router default settings.
Scroll down and click **Modify** to enable edit mode. Edit the SSID to **IOT_FALL_2022_WIFI_YourInitials**. 
Make sure to also change the default Wi-Fi key to make your own password before you click **Apply**.
- You will be automatically disconnected from the default router Wi-fi after making these changes.
Wait until the SSID change is effective and the new Wi-Fi name appears in the available networks.
Connect to the Wi-fi using the new password you created and refresh the Admin Panel site.

## Repeater setup
Using the repeater means connecting the router to another existing wireless network and retransmitting the signal.

- On the main **Internet** tab on the Admin Panel, scroll down and click **_scan_** in the **Repeater** section.
- Choose a SSID from the drop-down list and enter its password.
Note: The GL-MT300N-V2(Mango) with certificate-based routing to connect to VUMobile without upgrading the firmware beforehand. 
See OptionalSetup.md located in this directory for additional information on firmware upgrades.
If you need to connect to the Villanova network, you will have to create a user account with VUGuest and use that Wi-Fi instead.
- If the connection is succesful, you will get a "Success" message and you will be sent back to the main tab.
The information of the network you have connected to will be displayed on the main screen shortly. 
![Successful Connection](/Images/Successful_Connection.jpeg)
