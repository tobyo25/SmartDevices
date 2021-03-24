#include "Config.h"


DeviceConfig Config::GetDeviceConfig(void)
{
  static DeviceConfig sConfig;
  sConfig.ssid = "SKYNET";
  sConfig.password = "quickfox01";
  sConfig.devicetype = DEVICE_NONE;

  return sConfig;
}
