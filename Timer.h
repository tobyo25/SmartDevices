#ifndef __TIMER_H
#define __TIMER_H
class Timer
{
  public:
    bool Expired(long timeout);
    void Reset(void);

  private:
    long ResetTime;
};

#endif
