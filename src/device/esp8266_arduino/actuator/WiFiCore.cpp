#include "WiFiCore.h"
#include "Global.h"

uint16_t delayMilis = 1000;
  
void WiFiBegin(const char* ssid, const char* pass)
{
  WiFi.begin(ssid, pass);
  Printf("Waiting for AP connection ...\n");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(delayMilis);
    Printf(".");
  }
  char deviceIP[LEN_IP_MAX] = {};
  WiFiGetIP(deviceIP);
  Printf("\nConnected to AP. IP : %s\n", deviceIP);
}

void WiFiGetIP(char* ipBuffer)
{
  memset(ipBuffer, 0, LEN_IP_MAX);
  IPAddress ip = WiFi.localIP();
  snprintf(ipBuffer, LEN_IP_MAX, "%d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]);
}

void WiFiGetSSID(char* ssidBuffer)
{
  memset(ssidBuffer, 0, LEN_SSID_MAX);
  strncpy(ssidBuffer, WiFi.SSID().c_str(), LEN_SSID_MAX);
}

void WiFiGetPassphrase(char* passBuffer)
{
  memset(passBuffer, 0, LEN_PASSPHRASE_MAX);
  strncpy(passBuffer, WiFi.psk().c_str(), LEN_PASSPHRASE_MAX);
}

