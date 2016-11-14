#include <ESP8266WiFi.h>
#include <Arduino.h>

#include "WiFiCore.h"
#include "MQTTConnector.h"
#include "Global.h"
#include "Credentials.h"

void SerialBegin()
{
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.setDebugOutput(true);
}

void setup() 
{
  SerialBegin();
  WiFiBegin(STA_SSID, STA_PASS);
  MQTTBegin();
}

void loop() 
{
  MQTTLoop();
}
