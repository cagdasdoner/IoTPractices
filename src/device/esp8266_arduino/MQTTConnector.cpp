#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "MQTTConnector.h"
#include "Global.h"
#include "Credentials.h"

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
static const Protocol_t protocol = MQTT;
boolean mqttInitCompleted = false;
String clientId = "IoTTraining-" + String(ESP.getChipId());

/* Incoming data callback. */
void dataCallback(char* topic, byte* payload, unsigned int length)
{
  Serial.printf("Data    : Topic : [%s]\n", topic);
  Serial.printf("Data    : Payload : ");
  for (int i = 0; i < length; i++)
  {
    Serial.printf("%c", (char)payload[i]);
  }
  Serial.printf("\n");
  
  /* Implement your action! */
}

void performConnect()
{
  uint16_t connection_delay = 5000;
  while (!mqttClient.connected())
  {
    Serial.printf("Trace   : Attempting MQTT connection...\n");
    if (mqttClient.connect(clientId.c_str(), MQTT_USERNAME, MQTT_KEY))
    {
      Serial.printf("Trace   : Connected to Broker.\n");

      /* Do subscribe to your related topic! */

      mqttClient.subscribe(MQTT_TOPIC_SENSOR);
    }
    else
    {
      Serial.printf("Error!  : MQTT Connect failed, rc = %d\n", mqttClient.state());
      Serial.printf("Trace   : Try again in %d msec.\n", connection_delay);
      delay(connection_delay);
    }
  }
}

boolean MQTTDeliver(const char* topic, const char* payload)
{
  boolean retval = false;
  if (mqttClient.connected())
  {
    retval = mqttClient.publish(topic, payload);
  }
  
  return retval;
}

void MQTTInit()
{
  mqttClient.setServer(MQTT_BROKER, MQTT_BROKER_PORT);
  mqttClient.setCallback(dataCallback);
  mqttInitCompleted = true;
}

void MQTTLoop()
{
  if(mqttInitCompleted)
  {
    if (!mqttClient.connected())
    {
      performConnect();
    }
    mqttClient.loop();
  }
}
