#ifndef ARDUINO_TEMPSENSOR_H
#define ARDUINO_TEMPSENSOR_H

#include <Arduino.h>

#define INVALID_TEMP_READ -196

void  TEMPInit();
float TEMPGet(uint8_t id);
void  TEMPGetString(uint8_t id, char* tempBuffer);
void  TEMPLoop();

#endif /* ARDUINO_TEMPSENSOR_H */
