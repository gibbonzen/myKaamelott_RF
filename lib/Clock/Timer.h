#ifndef Timer_h
#define Timer_h

#include <functional>
#include "Clock.h"
#include "ClockListener.h"

class Timer : public ClockListener {
  public:
    Timer(int millis, std::function<void()> func);
    void start();
    void handle(Clock *clock);

  private:
    void done();

    int _timer;
    unsigned long _count;
    std::function<void()> _func;
    bool _isStarted;
};

#endif