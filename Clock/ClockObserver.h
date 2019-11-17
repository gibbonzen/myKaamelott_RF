#ifndef ClockObserver_h
#define ClockObserver_h

#include "Clock.h"
#include "ClockListener.h"

class ClockObserver : public ClockListener {
  public:
    ClockObserver(Clock *clock);
    void setID(int id);
    int getID();
    void at(int const& hour, int const& min, int const& sec, void (*func)(void));
    void start();
    void stop();
    void handle(Clock *clock);
    void execute(void (*func)(void));

  private:
    int _id;
    long _time;
    int _h;
    int _m;
    int _s;
    bool _isStarted;
    bool waiting_ = true;
    void (*_func)(void);
};

#endif