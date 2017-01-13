#ifndef ARDUINO_HARDWARE_H
#define ARDUINO_HARDWARE_H

#define BAUD_RATE   9600

#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial

//#define USE_DS18B20_TEMP_SENSOR

/* GPIO Definitions */
static const uint8_t pinMap[11] = {16, 5, 4, 0, 2, 14, 12, 13, 15, 3, 1};

#define VIRTUAL_PIN_SWITCH_1  1
#define VIRTUAL_PIN_SWITCH_2  2
#define VIRTUAL_PIN_TEMP_1    3

#endif /* ARDUINO_HARDWARE_H */
