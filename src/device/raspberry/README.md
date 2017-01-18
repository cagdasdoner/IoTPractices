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






