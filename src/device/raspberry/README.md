Setup Guide for Raspberry

1. git clone https://github.com/eclipse/paho.mqtt.c.git
2. cd paho.mqtt.c.git
3. make
4. sudo make install


NOTE: Raspberry need to have OpenSSL and Curl libraries. Type them :
1. sudo apt-get install libssl-dev
2. sudo apt-get install libcurl3


To compile and run the workshop code, use type them below :
1. make all
2. ./workshop


This tiny app aims to subscribe to a topic and post retrieved data to ThingSpeak or any other cloud service.




