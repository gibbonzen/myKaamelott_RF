#ifndef ClockObserver_h
#define ClockObserver_h

#include "Clock.h"

class ClockObserver {
  public:
    ClockObserver(Clock *clock);
    void at(int const& hour, int const& min, int const& sec, void (*func)(void));
    void start();
    void stop();
    void handle();
    ~ClockObserver();

  private:
    long _time;
    bool _isStarted;
    bool _isHandled;
    unsigned long _handledAt;
    Clock *_clock;
    void (*_func)(void);
};

#endif