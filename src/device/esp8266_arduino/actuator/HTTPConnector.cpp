#include <ESP8266HTTPClient.h>

#include "HTTPConnector.h"
#include "Credentials.h"
#include "Global.h"

HTTPClient http;

unsigned short postThingSpeak(char* data)
{
  boolean httpCode = 0;
  char httpPath[LEN_HTTP_PATH_MAX];
  memset(httpPath, 0, LEN_HTTP_PATH_MAX);
  snprintf(httpPath, LEN_HTTP_PATH_MAX, "%s/update?api_key=%s&field1=%s", TSPEAK_HOST, TSPEAK_API_KEY, data);
  Printf("Trace   : Path to post : %s\n", httpPath);

  http.begin(httpPath);
  /* HTTPS config. */
  //http.begin(httpPath, "7a 9c f4 db 40 d3 62 5a 6e 21 bc 5c cc 66 c8 3e a1 45 59 38");
  httpCode = http.GET();

  Printf("Trace   : Return  : %d\n", httpCode);
  Printf("Trace   : Incoming Body : %s\n", http.getString().c_str());
  http.end();
  
  return httpCode;
}

boolean HTTPPostCloud(char* data)
{
  boolean retval = false;
  if (postThingSpeak(data) == HTTP_OK)
  {
    retval = true;
  }
  
  return retval;
}

