#include "ClockObserver.h"
#include "Clock.h"
//#include <Arduino.h>

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