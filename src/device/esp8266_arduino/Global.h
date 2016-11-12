#ifndef ARDUINO_GLOBAL_H
#define ARDUINO_GLOBAL_H

#define PRINTF Serial.printf

#define SERIAL_BAUD_RATE 9600

typedef enum Protocol
{
  WebSocket = 0,
  MQTT,
  HTTP
}Protocol_t;

/* Board Definitions */
#define USE_NODEMCU_BOARD
//#define USE_GENERIC_ESP8266
//#define USE_ADAFRUIT_HUZZAH

/* GPIO Definitions */
static const uint8_t pinMap[11] = {16, 5, 4, 0, 2, 14, 12, 13, 15, 3, 1};

#endif /* ARDUINO_GLOBAL_H */
