#ifndef ClockObserver_h
#define ClockObserver_h

#include "Clock.h"

class ClockObserver {
  public:
    ClockObserver(Clock *clock);
    void at(int const& hour, int const& min, int const&sec, void (*func)());
    void start();
    void stop();
    ~ClockObserver();

  private:
    void listen();
    int _hour;
    int _min;
    int _sec;
    bool _isStarted;
    Clock *_clock;
    void (*_func)();
};

#endif