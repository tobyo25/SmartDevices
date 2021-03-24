#include "Device.h"
#include "System.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>


Config oConfig;
DeviceConfig sConfig;

//Timers
Timer UpdateTimer;

DeviceStatus eDeviceStatus;



Device::Device()
{
  sConfig.enableLog = true;
  sConfig = oConfig.GetDeviceConfig();
  eDeviceStatus = DEVICE_STATUS_NONE;
  
  UpdateTimer.Reset();
}



void Device::Update(void)
{
  if(sConfig.devicetype == DEVICE_NONE && eDeviceStatus == DEVICE_STATUS_NONE)
  {     
    eDeviceStatus = DEVICE_NOT_CONFIGURED;
  }else
  {
    if(sConfig.devicetype != DEVICE_NONE)
    eDeviceStatus = DEVICE_NO_WIFI_CONNECTION;
  }

  switch (eDeviceStatus)
  {
    case DEVICE_NOT_CONFIGURED:
    eDeviceStatus = DEVICE_NO_WIFI_CONNECTION;
    break;   
    case DEVICE_NO_WIFI_CONNECTION:
      Serial.println("Connecting to WiFi");
      WiFiSTAInit();
      WiFiReconnect();
    break;
    
    case DEVICE_NOT_CONNECTED_TO_BROKER:
    if(UpdateTimer.Expired(1000))
    { 
      UpdateTimer.Reset();
      Serial.println("Connecting to broker...");
    }
     
    break;
     
  }
}
void Device::SerialInit(void)
{
  Serial.begin(115200);
}
void Device::WiFiSTAInit(void)
{
  WiFi.mode(WIFI_AP_STA);
}

bool Device::GetWiFiStatus(void)
{
  return WiFi.status();
}



void Device::WiFiReconnect(void)
{
   WiFi.begin(sConfig.ssid, sConfig.password);
  while (WiFi.status() != WL_CONNECTED) {    
    Serial.print(".");
    delay(500);
  }
  eDeviceStatus = DEVICE_NOT_CONNECTED_TO_BROKER;
}
