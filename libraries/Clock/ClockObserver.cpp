#include "ClockObserver.h"
#include "Clock.h"
#include "TimerUtils.h"

ClockObserver::ClockObserver(Clock *clock) {
  _isHandled = false;
  _handledAt = 0;

  clock->attach(this);
}

void ClockObserver::setID(int id) {
  _id = id;
}

int ClockObserver::getID() {
  return _id;
}

void ClockObserver::at(int const& hour, int const& min, int const& sec, void (*func)(void)) {
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
  if(!_isStarted) return;

  if(_isHandled) {
    if(clock->getTime() > _handledAt + 1000) {
      _handledAt = 0;
      _isHandled = false;
    }
    else return;
  }
  
  if(!_isHandled && _time == clock->getTime()) {
    _func();
    _isHandled = true;
    _handledAt = clock->getTime(); 
  }

}