#ifndef __CONFIG_H
#define __CONFIG_H

typedef enum _DeviceType
{
  DEVICE_NONE,
  DEVICE_LIGHT,
  DEVICE_RGB_LIGHT,
  DEVICE_MOTION_SENSOR
}DeviceType;
typedef struct _DeviceConfig
{
  const char* ssid = "SKYNET";
  const char* password = "quickfox01";
  DeviceType devicetype;
  bool enableLog;
  bool wifiStatus;
}DeviceConfig;

class Config
{
  public:
    void LoadDeviceConfig(void);
    DeviceConfig GetDeviceConfig(void);
};
#endif
