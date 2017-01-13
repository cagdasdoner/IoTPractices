/*
Cayenne WiFi Example

This sketch connects to the Cayenne server using an Arduino WiFi shield
and runs the main communication loop.

The Cayenne Library is required to run this sketch. If you have not already done so you can install it from the Arduino IDE Library Manager.

Steps:
1. Set the token variable to match the Arduino token from the Dashboard.
2. Set the network name and password.
3. Compile and upload this sketch.

For Cayenne Dashboard widgets using digital or analog pins this sketch will automatically
send data on those pins to the Cayenne server. If the widgets use Virtual Pins, data
should be sent to those pins using virtualWrites. Examples for sending and receiving
Virtual Pin data are under the Basics folder.
*/

#include "Credentials.h"
#include "Hardware.h"

#include "CayenneDefines.h"
#include "BlynkSimpleEsp8266.h"
#include "CayenneWiFiClient.h"

#ifdef USE_DS18B20_TEMP_SENSOR
#include <OneWire.h>
#include <DallasTemperature.h>
/* Digital pin the DS18B20 is connected to. */
const int tempPin = pinMap[2];
/* Setting up one-wire protocol for sensor. */
OneWire oneWire(tempPin);
DallasTemperature sensors(&oneWire);
#endif

void setup()
{
  pinMode(pinMap[4], OUTPUT);
  pinMode(pinMap[3], OUTPUT);
  Serial.begin(9600);
  delay(10);
  Cayenne.begin(CAYENNE_TOKEN, STA_SSID, STA_PASS);
#ifdef USE_DS18B20_TEMP_SENSOR  
  sensors.begin();
#endif
}

void loop()
{
  Cayenne.run();
}

CAYENNE_IN(VIRTUAL_PIN_SWITCH_1)
{
  int value = getValue.asInt();
  CAYENNE_LOG("Got a value: %d", value);
 
  if (value == 0)
  {
    digitalWrite(pinMap[4], LOW);
  }
  else
  {
    digitalWrite(pinMap[4], HIGH);
  } 
}

CAYENNE_IN(VIRTUAL_PIN_SWITCH_2)
{
  int value = getValue.asInt();
  CAYENNE_LOG("Got a value: %d", value);
 
  if (value == 0)
  {
    digitalWrite(pinMap[3], LOW);
  }
  else
  {
    digitalWrite(pinMap[3], HIGH);
  } 
}

#ifdef USE_DS18B20_TEMP_SENSOR
CAYENNE_OUT(VIRTUAL_PIN_TEMP_1)
{
  sensors.requestTemperatures();
  Cayenne.celsiusWrite(VIRTUAL_PIN_TEMP_1, sensors.getTempCByIndex(0));
}
#endif
