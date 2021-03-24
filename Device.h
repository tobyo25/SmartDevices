#ifndef __DEVICE_H
#define __DEVICE_H

typedef enum _DeviceStatus
{
  DEVICE_STATUS_NONE,
  DEVICE_NOT_CONFIGURED,
  DEVICE_RUNNING,
  DEVICE_NO_WIFI_CONNECTION,
  DEVICE_NOT_CONNECTED_TO_BROKER,
  DEVICE_FIRMWARE_UPGRADE,
}DeviceStatus;


class Device
{
  public:
    Device();
   
    void SerialInit(void);
    bool GetWiFiStatus(void);
    void Update(void);
  private:
    void WiFiReconnect(void);
    void WiFiSTAInit(void);
    
    
};

#endif
