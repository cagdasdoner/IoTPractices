#include <OneWire.h>
#include <DallasTemperature.h>

#include "TempSensor.h"
#include "Global.h"

const uint8_t sensitivity = 12;
const uint8_t temp_delay = 10;
bool temp_init_done = false;

/* Library lacks empty constructor.
 * Not able to trigger from Hardware.cpp. Think to add it to the lib.
 */
OneWire oneWire(pinMap[2]);
DallasTemperature sensors;
DeviceAddress thermos;

void printAddress(DeviceAddress deviceAddress)
{
  Printf("Data    : printAddress. Sensor Address :\n");
  const uint8_t addr_len = 8;
  for (uint8_t i = 0; i < addr_len; i++)
  {
    Printf("%x", deviceAddress[i]);
  }
  Printf("\n");
}

void printTemperature()
{
  char tempStr[LEN_TEMP_MAX];
  TEMPGetString(0, tempStr);
  if(strlen(tempStr))
  {
    Printf("Data    : printTemperature. %s\n", tempStr);
  }
  else
  {
    Printf("Error!  : Could not retrieve sensor data!\n");
  }
}

void TEMPInit()
{
  sensors.setOneWire(&oneWire);
  delay(temp_delay);
  sensors.begin();
  Printf("Trace   : Found %d Sensor devices.\n", sensors.getDeviceCount());
  temp_init_done = true;
}

float TEMPGet(uint8_t id)
{
  float retval = INVALID_TEMP_READ;
  DeviceAddress temper;
  if (sensors.getDeviceCount() && sensors.getAddress(temper, id))
  {
    sensors.setResolution(temper, sensitivity);
    retval = sensors.getTempC(temper);
  }

  return retval;
}

void TEMPGetString(uint8_t id, char* tempBuffer)
{
  sensors.requestTemperatures();
  DeviceAddress temper;
  memset(tempBuffer, 0, LEN_TEMP_MAX);
  if (sensors.getDeviceCount() && sensors.getAddress(temper, id))
  {
    sensors.setResolution(temper, sensitivity);
    const uint8_t data_len = 3;
    const uint8_t data_prec_len = 2;
    dtostrf(sensors.getTempC(temper), data_len, data_prec_len, tempBuffer);
  }
}

void TEMPLoop()
{
  if(temp_init_done)
  {
    /*if(sensors.getDeviceCount())
    {
      sensors.requestTemperatures();
    }*/
  }
}


