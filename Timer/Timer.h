#ifndef TIMER_H
#define TIMER_H

#include "Clock.h"
#include "ClockListener.h"
#include "GPIO.h"

class Timer : public ClockListener {
  public:
    Timer(unsigned long millis);
    void setCallback(void (GPIO::*f)(), GPIO *obj);
    void start();
    void stop();
    bool isStarted();
    void handle(Clock *clock);

  private:
    void done();

    unsigned long _millis;
    unsigned long _count = 0;
    void (GPIO::* _func)();
    GPIO *_obj;
    bool _isStarted = false;
};

Timer::Timer(unsigned long millis) {
  _millis = millis;
}

void Timer::setCallback(void (GPIO::*func)(), GPIO *obj) {
  _func = func;
  _obj = obj;
}

void Timer::start() {
  _count = 0;
  _isStarted = true;
}

void Timer::stop() {
  _isStarted = false;
}

bool Timer::isStarted() {
  return _isStarted;
}

void Timer::done() {
  _isStarted = false;
  // Serial.println("Timer is done");
}

void Timer::handle(Clock *clock) {
  if(!_isStarted) {
    // Serial.println("Timer is not started...");
    return;
  }

  if(_count == 0) {
    _count = clock->milli();
    // Serial.print("Current time: ");
    // Serial.println(_count);
    // Serial.print("End at: ");
    // Serial.println(_count + _millis);
  }

  // Serial.print("Timer (");
  // Serial.print(clock->getMillis());
  // Serial.print("): ");
  // Serial.println(_count + _millis - clock->getMillis());

  if(clock->milli() - _count >= _millis) {
    // Serial.println("Handler timer start");
    (_obj->*_func)();
    done();
  }
}

#endif