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

#include "CayenneDefines.h"
#include "BlynkSimpleEsp8266.h"
#include "CayenneWiFiClient.h"

#include "Credentials.h"
#include "Hardware.h"

void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(pinMap[16], OUTPUT);
  pinMode(pinMap[5], OUTPUT);
  Cayenne.begin(CAYENNE_TOKEN, STA_SSID, STA_PASS);
}

CAYENNE_IN(VIRTUAL_PIN)
{
  /* get value sent from dashboard */
  int currentValue = getValue.asInt();

  /* Using low level trigger due to 3.3V. */
  if (currentValue == 0)
  {
    digitalWrite(pinMap[16], HIGH);
  }
  else
  {
    digitalWrite(pinMap[16], LOW);
  }
}

CAYENNE_IN(VIRTUAL_PIN2)
{
  /* get value sent from dashboard */
  int currentValue = getValue.asInt();

  /* Using low level trigger due to 3.3V. */
  if (currentValue == 0)
  {
    digitalWrite(pinMap[5], HIGH);
  }
  else
  {
    digitalWrite(pinMap[5], LOW);
  }
}

void loop()
{
  Cayenne.run();
}
