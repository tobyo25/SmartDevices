#include "Device.h"
#include "Timer.h"
Device oDevice;
Timer oTimer;
void setup() {
  // put your setup code here, to run once:
 oDevice.SerialInit();
 oTimer.Reset();
 }

void loop() {
  // put your main code here, to run repeatedly:
  oDevice.Update();
}
