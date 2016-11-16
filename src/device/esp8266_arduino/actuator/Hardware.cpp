#include "Hardware.h"
#include "Global.h"

short hw_delay = 10;

void SerialInit()
{
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.setDebugOutput(true);
  delay(hw_delay);
}

void GPIOInit()
{
#ifdef USE_NODEMCU_BOARD
  pinMode(pinMap[8], OUTPUT);
  pinMode(pinMap[9], OUTPUT);
  /* pinMap[2] will be used for one-wire DQ. */
#else
  pinMode(pinMap[6], OUTPUT);
  pinMode(pinMap[7], OUTPUT);
#endif
  delay(hw_delay);
}

void HWInit()
{
  SerialInit();
  GPIOInit();
}

void HWRestart()
{
  ESP.restart();
}

