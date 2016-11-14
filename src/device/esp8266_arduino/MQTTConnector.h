#ifndef ARDUINO_MQTTCONNECTOR_H
#define ARDUINO_MQTTCONNECTOR_H

#include <Arduino.h>

#define MQTT_TOPIC_SENSOR  "/iot/text/sensor"

#define MQTT_TYPE_INIT     "mqtt_init"

void MQTTBegin();
void MQTTLoop();
boolean MQTTDeliver(const char* topic, const char* payload);

#endif /* ARDUINO_MQTTCONNECTOR_H */
