#include "Timer.h"
#include "Arduino.h"
void Timer::Reset(void)
{
  ResetTime = millis();
}

bool Timer::Expired(long timeout)
{
  bool bExpired = false;
  long EndTime;
  long CurrentTime;
  EndTime = ResetTime + timeout;
  CurrentTime = millis();

  if(ResetTime < EndTime)
  {
    if(CurrentTime >= EndTime)
    {     
        bExpired = true;      
    }
    
  }else
  {
    if(CurrentTime >= EndTime)
    {
        bExpired = true;
    }
  }
  return bExpired;
}
