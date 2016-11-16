#include "Timer.h"
#include "MQTTConnector.h"
#include "Hardware.h"
#include "Global.h"

/* Catastrophically using symbols from ESP OpenSDK directly. */
extern "C" {
#include "user_interface.h"
}

os_timer_t publishTimer;
boolean publishTimerTick = false;
unsigned int timerDelay = 10000;

void publishCallback(void *pArg)
{
  /* Keep our ISR light! */
  publishTimerTick = true;
}

void TIMERInit()
{
  os_timer_setfn(&publishTimer, publishCallback, NULL);
  os_timer_arm(&publishTimer, timerDelay, true);
  publishTimerTick = false;
}

void TIMERLoop()
{
  if(publishTimerTick)
  {
    if(MQTTConnected())
    { 
      char tempStr[LEN_TEMP_MAX];
      HWGetTempString(0, tempStr);
      if(strlen(tempStr))
      {
        /* Publish to the topic */
        Printf("Trace   : MQTT publish on the go.\n");
        if(!MQTTDeliver(MQTT_TOPIC_SENSOR, tempStr))
        {
          Printf("Error!  : Publishment has not succeeded!\n");
        }
      }
      else
      {
        Printf("Error!  : Could not retrieve sensor data!\n");
      }
    }
    else
    {
      Printf("Warning: MQTT not connected yet!\n");
    }
    publishTimerTick = false;
  }
}

