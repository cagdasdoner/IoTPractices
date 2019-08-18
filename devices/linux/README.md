## Guide for Linux based (Raspberry, BeagleBone, Ubuntu etc.) systems

* Raspberry users: Before proceeding, be sure that you have installed right image into your Raspberry device if you will proceed with that one. Please follow up [instructions](https://www.raspberrypi.org/documentation/installation/installing-images/) if you haven't done it yet.
* Raspberry and BeagleBone users: You will need to get device IP address to establish an SSH connection to access to the shell. You can connect your device to a TV via HDMI to get it under *Network Settings*. For detailed SSH info, check this [link](https://www.raspberrypi.org/documentation/remote-access/ssh/). Once you are ready with your shell, you can proceed.
* Raspberry and BeagleBone users: It is supposed that you have Internet access on your device via Wi-Fi or Ethernet. Please configure them before proceeding.
* Be sure that you have the git client to get our sample code and required libraries by typing below commands into your command line:
```
$ sudo apt-get install git
```
* Clone required MQTT client library into your system and type following commands to install it :
```
$ git clone https://github.com/eclipse/paho.mqtt.c.git
$ cd paho.mqtt.c.git
$ make
$ sudo make install
```
* Your system may need to have OpenSSL and Curl libraries. If necessary type these commands in your shell :
```
$ sudo apt-get install libssl-dev
$ sudo apt-get install libcurl4-openssl-dev
```
* Now you are ready to get the sample code. Get IoTPractices repository via git or just download as [zip](https://github.com/cagdasdoner/IoTPractices) :
```
$ git clone https://github.com/cagdasdoner/IoTPractices.git
```
* Now, switch to Linux/Raspberry workshop code directory :
```
$ cd IoTPractices/devices/linux/actuator
```
* After getting the code, you will need to change the initial credentials with yours. Navigate to **credentials.h** file and change below fields :
```
/* MQTT credentials */
#define CLIENTID        "YOUR_CLIENT_ID_OR_MAC_LIKE_UNIQUE_NUMBER"
#define BROKER_ADDR     "tcp://www.maqiatto.com"
#define USERNAME        "YOUR_MQTT_USER"
#define PASSWORD        "YOUR_MQTT_PASS"
```
* NOTICE that, [maqiatto.com](https://www.maqiatto.com) will be your MQTT broker during the practice. For **CLIENTID** field, lease assign a random and unique id for each of your clients, i.e. use your MAC address or just assign date-time info of the current moment.
* After modifications, code compilation need to be done. Basically type :
```
$ make
```
* After successful compilation you will get the execuable file called **workshop** under same directory. Run it :
```
$ ./workshop
```
* Now you are ready to follow up the given instructions in the workshop.




















Setup Guide for Raspberry


This tiny app aims to subscribe to a topic and post retrieved data to ThingSpeak or any other cloud service.


Get MQTT client library : 
1. git clone https://github.com/eclipse/paho.mqtt.c.git
2. cd paho.mqtt.c.git
3. make
4. sudo make install


NOTE: Raspberry may need to have OpenSSL and Curl libraries. Type them :
1. sudo apt-get install libssl-dev
2. sudo apt-get install libcurl4-openssl-dev


Go for workshop code :
1. git clone git clone https://github.com/cagdasdoner/IoTPractices.git
2. cd IoTPractices/src/device/raspberry
3. Change your credentials such as broker address under credentials.h.
4. Review the code and do your implementation on required files as denoted in workshop.


To compile and run the workshop code, use type them below :
1. make
2. ./workshop 






