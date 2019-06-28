#include "Timer.h"
#include "../GPIO/GPIO.h"

Timer::Timer(int millis) {
  _timer = millis;
}

void Timer::setCallback(void (GPIO::*func)(), GPIO *obj) {
  _func = func;
  _obj = obj;
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
    (_obj->*_func)();
    done();
  }
}