#include <functional>
#include "ClockObserver.h"
#include "Clock.h"
#include "../TimerUtils/TimerUtils.h"

#include <iostream>

using namespace std;
using namespace std::placeholders;

ClockObserver::ClockObserver(Clock *clock) {
  _clock = clock;
  _isHandled = false;
  _handledAt = 0;

  _clock->attach(this);
}

ClockObserver::~ClockObserver() {
  delete _clock;
}

void ClockObserver::setID(int id) {
  _id = id;
}

int ClockObserver::getID() {
  return _id;
}

void ClockObserver::at(int const& hour, int const& min, int const& sec, std::function<void()> func) {
  _time = TimerUtils::convert(hour, TimerUtils::HOUR) + TimerUtils::convert(min, TimerUtils::MINUTE) +  TimerUtils::convert(sec, TimerUtils::SECOND);
  _func = func;
}

void ClockObserver::execute(std::function<void()> func) {
  func();
}

void ClockObserver::start() {
  _isStarted = true;
}

void ClockObserver::stop() {
  _isStarted = false;
}

void ClockObserver::handle() {
  // Stopped
  if(!_isStarted) return;

  if(_isHandled) {
    if(_clock->getTime() > _handledAt + 1000) {
      _handledAt = 0;
      _isHandled = false;
    }
    else return;
  }
  
  if(!_isHandled && _time == _clock->getTime()) {
    _func();
    _isHandled = true;
    _handledAt = _clock->getTime(); 
  }

}