#ifndef ClockObserver_h
#define ClockObserver_h

#include <functional>

#include "Clock.h"
#include "ClockListener.h"

using namespace std::placeholders;

class ClockObserver : public ClockListener {
  public:
    ClockObserver(Clock *clock);
    void setID(int id);
    int getID();
    void at(int const& hour, int const& min, int const& sec, std::function<void()> func);
    void start();
    void stop();
    void handle(Clock *clock);
    void execute(std::function<void()> func);

  private:
    int _id;
    long _time;
    bool _isStarted;
    bool _isHandled;
    unsigned long _handledAt;
    std::function<void()> _func;
};

#endif