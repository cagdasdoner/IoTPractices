#ifndef ARDUINO_HARDWARE_H
#define ARDUINO_HARDWARE_H

#include <Arduino.h>

void  HWInit();
void  HWRestart();
float HWGetTempString(uint8_t id, char* tempBuf);
void  HWLoop();

#endif /* ARDUINO_HARDWARE_H */
