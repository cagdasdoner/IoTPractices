#include "Hardware.h"
#include "TempSensor.h"
#include "Global.h"

uint16_t hw_delay = 10;
uint16_t hw_init_done = false;

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
  TEMPInit();
  hw_init_done = true;
}

void HWRestart()
{
  ESP.restart();
}

float HWGetTempString(uint8_t id, char* tempBuf)
{
  TEMPGetString(id, tempBuf);
}

void HWLoop()
{
  if(hw_init_done)
  {
    TEMPLoop();
  }
}
