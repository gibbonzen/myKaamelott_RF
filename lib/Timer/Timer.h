#ifndef Timer_h
#define Timer_h

#include "../Clock/Clock.h"
#include "../Clock/ClockListener.h"
#include "../GPIO/GPIO.h"

class Timer : public ClockListener {
  public:
    Timer(int millis);
    void setCallback(void (GPIO::*f)(), GPIO *obj);
    void start();
    void handle(Clock *clock);

  private:
    void done();

    int _timer;
    unsigned long _count;
    void (GPIO::* _func)();
    GPIO *_obj;
    bool _isStarted;
};

#endif