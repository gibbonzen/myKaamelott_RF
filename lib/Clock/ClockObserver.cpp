#include "ClockObserver.h"
#include "Clock.h"

#include <iostream>

using namespace std;

ClockObserver::ClockObserver(Clock *clock) {
  _clock = clock;
  _isHandled = false;
  _handledAt = 0;

  _clock->attach(*this->handle);
}

ClockObserver::~ClockObserver() {
  delete _clock;
}

void ClockObserver::at(int const& hour, int const& min, int const&sec, void (*func)()) {
  _time = TimerUtils::convert(hour, TimerUtils::HOUR) + TimerUtils::convert(min, TimerUtils::MINUTE) +  TimerUtils::convert(sec, TimerUtils::SECOND);
  _func = func;
}

void ClockObserver::start() {
  _isStarted = true;
}

void ClockObserver::stop() {
  _isStarted = false;
}

void ClockObserver::handle() {
  cout << "handle" << endl;

  // Stopped
  if(!_isStarted) return;

  if(_isHandled && _handledAt + 1000 >= _clock->getTime()) {
    
  }
  else {
    _isHandled = false;
    _handledAt = 0;
  }
  

  if(!_isHandled && _time == _clock->getTime()) {
    _handledAt = _clock->getTime(); 
    _isHandled = true;
    _func();
  }

}