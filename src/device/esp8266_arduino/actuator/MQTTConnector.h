#ifndef ARDUINO_MQTTCONNECTOR_H
#define ARDUINO_MQTTCONNECTOR_H

#include <Arduino.h>

#define MQTT_TOPIC_SENSOR  "/iot/text/sensor"
#define MQTT_TOPIC_RELAY   "/iot/text/relay"

void    MQTTBegin();
void    MQTTLoop();
boolean MQTTDeliver(const char* topic, const char* payload);
boolean MQTTSubscribe(const char* topicToSubscribe);
boolean MQTTConnected();

#endif /* ARDUINO_MQTTCONNECTOR_H */
