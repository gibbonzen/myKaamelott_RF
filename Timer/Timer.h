#ifndef Timer_h
#define Timer_h

#include "Clock.h"
#include "ClockListener.h"
#include "GPIO.h"

class Timer : public ClockListener {
  public:
    Timer(unsigned long millis);
    void setCallback(void (GPIO::*f)(), GPIO *obj);
    void start();
    void stop();
    bool isStarted();
    void handle(Clock *clock);

  private:
    void done();

    unsigned long _millis;
    unsigned long _count = 0;
    void (GPIO::* _func)();
    GPIO *_obj;
    bool _isStarted = false;
};

#endif