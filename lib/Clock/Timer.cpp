#include "Timer.h"
#include <functional>

Timer::Timer(int millis, std::function<void()> func) {
  _timer = millis;
  _func = func;
}

void Timer::start() {
  _isStarted = true;
}

void Timer::done() {
  _isStarted = false;
  _count = 0;
}

void Timer::handle(Clock *clock) {
  if(!_isStarted) return;
  
  if(_count == 0) {
    _count = clock->getTime() + _timer;
  }

  if(clock->getTime() >= _count) {
    _func();
    done();
  }
}