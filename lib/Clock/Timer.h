#ifndef Timer_h
#define Timer_h

#include "Clock.h"
#include "ClockListener.h"
#include "Callable.h"

class Timer : public ClockListener {
  public:
    Timer(int millis);
    // Timer(int millis, void (*func)(void));
    void setCallback(void (Callable::*func)(), Callable *obj);
    void start();
    void handle(Clock *clock);

  private:
    void done();

    int _timer;
    unsigned long _count;
    void (Callable::* _func)();
    Callable *_obj;
    bool _isStarted;
};

#endif