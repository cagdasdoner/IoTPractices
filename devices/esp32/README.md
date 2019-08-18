## Guide for ESP32

### Environment Setup for ESP32
* Before start, please follow [this](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html#get-started-get-esp-idf) brilliant setup guide to make your environment ready with ESP32.

### Get ESP32 Sample Code
* Get IoTPractices repository via git or just download as [zip](https://github.com/cagdasdoner/IoTPractices) :
```
$ git clone https://github.com/cagdasdoner/IoTPractices.git
```
* Now, switch to ESP32 Arduino workshop code directory :
```
$ cd IoTPractices/devices/esp32
```

### Configuring the Device with your Credentials
* Navigate into sample code's directory.
* Type below command to set your configurations first :
```
$ make menuconfig
```
* From the opened **config menu** screen, we will first configure our Wi-Fi credentials. To do that, select **Example Connection Configuration** like given below :  
![Alt text](img/menuconfig.png?raw=true "Menuconfig")
* Provide your SSID and Password into the opening screen :  
![Alt text](img/connectionconfig.png?raw=true "WiFi configuration")
* Save and exit. 
* Jump into the **MaQiaTTo MQTT Configuration** tab to provide MQTT credentials of your user :  
![Alt text](img/maqiattoconfig.png?raw=true "MaQiaTTo configuration menu")
* NOTICE that, [maqiatto.com](https://www.maqiatto.com) will be your MQTT broker during the practice.
* You will be asked for your MQTT **username**, **password** and test **topic**. Provide them into the menu :  
![Alt text](img/mqttconfig.png?raw=true "MQTT configuration")
* Save and exit. 
* Now your configuration is ready to connect to WiFi and MQTT Broker. Exit from the **menuconfig** to the console.
* After completing the steps above, you will be ready to complete given instructions and practices in workshop.

### Running the Sample Code
* Be sure that your ESP32 device is connected to your PC and type the below command both to compile and flash :
```
$ make flash
```
* After it succeeds, navigate to the monitor tool with below command to check your connection :
```
$ make monitor
```
* Device will start to run and connect to maqiatto.com, which is your MQTT Broker. You can follow up the logs related with your device status.
