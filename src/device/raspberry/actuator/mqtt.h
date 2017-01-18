#ifndef RASPBERRY_MQTT
#define RASPBERRY_MQTT

#define SENSOR_TOPIC    "/iot/text/sensor"
#define RELAY_TOPIC     "/iot/text/sensor"

#define QOS             1
#define TIMEOUT         10000L
#define KEEP_ALIVE      20

void MQTTBegin();
void MQTTSubscribe(const char* topic);
void MQTTPublish(const char* topic, char* payload);
void MQTTDisconnect();

#endif /* RASPBERRY_MQTT */
