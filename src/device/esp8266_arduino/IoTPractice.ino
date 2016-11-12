#include <Arduino.h>
#include "MQTTConnector.h"
#include "Global.h"

void setup() 
{
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.setDebugOutput(true);
  MQTTInit();
}

void loop() 
{
  MQTTLoop();
}