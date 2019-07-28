#include "Timer.h"
#include "GPIO.h"
// #include <Arduino.h>

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
  if(!_isStarted) {
    // Serial.println("Timer is not started...");
    return;
  }

  long current = clock->getTime();
  if(_count == 0) {
    _count = current + _timer;
  }

  if(current == _count) {
    (_obj->*_func)();
    done();
  }
}