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
    bool _isStarted = false;
    bool waiting_ = true;
    void (*_func)(void);
};


ClockObserver::ClockObserver(Clock *clock) {
  clock->attach(this);
}

void ClockObserver::setID(int id) {
  _id = id;
}

int ClockObserver::getID() {
  return _id;
}

void ClockObserver::at(int const& hour, int const& min, int const& sec, void (*func)(void)) {
  _h = hour;
  _m = min;
  _s = sec;
  _func = func;
}

void ClockObserver::execute(void (*func)(void)) {
  func();
}

void ClockObserver::start() {
  _isStarted = true;
}

void ClockObserver::stop() {
  _isStarted = false;
}

void ClockObserver::handle(Clock *clock) {
  if(clock->second() > _s) {
    waiting_ = true;
  }

  // Stopped
  if(!_isStarted || !waiting_) {
    //Serial.println("Observer is not observing...");
    return;
  }

  if(clock->isTime(_h, _m, _s)) {
    waiting_ = false;
    _func();
  }

}

#endif