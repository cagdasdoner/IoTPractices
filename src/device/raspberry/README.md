Setup Guide for Raspberry

git clone https://github.com/eclipse/paho.mqtt.c.git
cd paho.mqtt.c.git
make
sudo make install

NOTE: Raspberry need to have OpenSSL and Curl libraries. Type it :
sudo apt-get install libssl-dev
sudo apt-get install libcurl3

To compile and run the workshop code, use type them below :
make all
./workshop

This tiny app aims to subscribe to a topic and post retrieved data to ThingSpeak or any other cloud service.




