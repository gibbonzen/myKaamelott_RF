#include "ClockObserver.h"
#include "Clock.h"
// #include "TimerUtils.h"

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
  _time = TimerUtils::convert(hour, TimerUtils::HOUR) + TimerUtils::convert(min, TimerUtils::MINUTE) +  TimerUtils::convert(sec, TimerUtils::SECOND);

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
  // Stopped
  if(!_isStarted) {
    // Serial.println("Observer is not observing...");
    return;
  }

  if(clock->getTime() == _time) {
  // if(clock->isTime(_h, _m, _s)) {
    _func();
  }

}