#include <ESP8266WiFi.h>
#include <Arduino.h>
#include "MQTTConnector.h"
#include "Global.h"
#include "Credentials.h"

void SerialInit()
{
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.setDebugOutput(true);
}

void WiFiInit()
{
  WiFi.begin(STA_SSID, STA_PASS);
  uint16_t delayMilis = 1000;
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(delayMilis);
    Serial.printf(".\n");
  }
}

void setup() 
{
  SerialInit();
  WiFiInit();
  MQTTInit();
}

void loop() 
{
  MQTTLoop();
}
