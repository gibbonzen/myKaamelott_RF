#ifndef Timer_h
#define Timer_h

#include "Clock.h"
#include "ClockListener.h"
#include "GPIO.h"

class Timer : public ClockListener {
  public:
    Timer(int millis);
    void setCallback(void (GPIO::*f)(), GPIO *obj);
    void start();
    void handle(Clock *clock);

  private:
    void done();

    long _timer;
    long _count = 0;
    void (GPIO::* _func)();
    GPIO *_obj;
    bool _isStarted;
};

#endif