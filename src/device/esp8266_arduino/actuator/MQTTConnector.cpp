#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "MQTTConnector.h"
#include "Global.h"
#include "Credentials.h"

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

static const Protocol_t protocol = MQTT;
boolean mqttInitCompleted = false;
String clientId = "IoTPractice-" + String(ESP.getChipId());

/* Incoming data callback. */
void dataCallback(char* topic, byte* payload, unsigned int length)
{
  char payloadStr[length + 1];
  memset(payloadStr, 0, length + 1);
  strncpy(payloadStr, (char*)payload, length);
  Printf("Data    : dataCallback. Topic : [%s]\n", topic);
  Printf("Data    : dataCallback. Payload : %s\n", payloadStr);

  /* Do your action in here ! */
}

/* MQTT connector function. */
void performConnect()
{
  uint16_t connection_delay = 5000;
  while (!mqttClient.connected())
  {
    Printf("Trace   : Attempting MQTT connection...\n");
    if (mqttClient.connect(clientId.c_str(), MQTT_USERNAME, MQTT_KEY))
    {
      Printf("Trace   : Connected to Broker.\n");
      
      /* Do subscribe to the topic in here ! */
    }
    else
    {
      Printf("Error!  : MQTT Connect failed, rc = %d\n", mqttClient.state());
      Printf("Trace   : Trying again in %d msec.\n", connection_delay);
      delay(connection_delay);
    }
  }
}

/* MQTT Publisher function. */
boolean MQTTDeliver(const char* topic, const char* payload)
{
  boolean retval = false;
  if (mqttClient.connected())
  {
    retval = mqttClient.publish(topic, payload);
  }
  return retval;
}

/* Init MQTT process */
void MQTTBegin()
{
  mqttClient.setServer(MQTT_BROKER, MQTT_BROKER_PORT);
  mqttClient.setCallback(dataCallback);
  mqttInitCompleted = true;
}

/* Sustain broker connection. */
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