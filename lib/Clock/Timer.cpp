#include "Timer.h"
#include "Callable.h"

Timer::Timer(int millis) {
  _timer = millis;
}

// Timer::Timer(int millis, void (*func)(void)): Timer(millis) {
//   setCallback(func);
// }

void Timer::setCallback(void (Callable::*func)(), Callable *obj) {
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