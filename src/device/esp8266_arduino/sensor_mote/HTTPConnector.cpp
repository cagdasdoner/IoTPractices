#include <ESP8266WiFi.h>
#include <ArduinoHttpClient.h>

#include "HTTPConnector.h"
#include "Credentials.h"
#include "Global.h"

WiFiClient wifi;
HttpClient thingSpeak = HttpClient(wifi, TSPEAK_HOST, TSPEAK_PORT);

unsigned short HTTPPostCloud(char* data)
{
  boolean retval = 0;
  char httpPath[LEN_HTTP_PATH_MAX];
  memset(httpPath, 0, LEN_HTTP_PATH_MAX);
  snprintf(httpPath, LEN_HTTP_PATH_MAX, "/update?api_key=%s&field1=%s", TSPEAK_API_KEY, data);
  Printf("path : %s\n", httpPath);
  if(thingSpeak.get(httpPath) == 0)
  {
    Printf("Trace   : Incoming Body : %d\n", thingSpeak.responseStatusCode());
    Printf("Trace   : Incoming Body : %s\n", thingSpeak.responseBody().c_str());
    retval = thingSpeak.responseStatusCode();
  }
  
  return retval;
}

