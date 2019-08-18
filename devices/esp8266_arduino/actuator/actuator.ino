#include <ESP8266WiFi.h>
#include <Arduino.h>

#include "WiFiCore.h"
#include "MQTTConnector.h"
#include "Hardware.h"
#include "Global.h"
#include "Credentials.h"

void setup() 
{
  HWInit();
  WiFiBegin(STA_SSID, STA_PASS);
  MQTTBegin();
}

void loop() 
{
  MQTTLoop();
}
