#ifndef TIMER_H
#define TIMER_H

#include "Clock.h"
#include "ClockListener.h"
#include "GPIO.h"

template<typename T>
class Timer : public ClockListener {
  public:
    Timer(unsigned long);
    void setCallback(void (T::*)(), T *);
    void start();
    void stop();
    bool isStarted();
    void handle(Clock*);

  private:
    void done();

    unsigned long _millis;
    unsigned long _count = 0;
    void (T::* _func)();
    T *_obj;
    bool _isStarted = false;
};

template<typename T>
Timer<T>::Timer(unsigned long millis) {
  _millis = millis;
}

template<typename T>
void Timer<T>::setCallback(void (T::*func)(), T *obj) {
  _func = func;
  _obj = obj;
}

template<typename T>
void Timer<T>::start() {
  _count = 0;
  _isStarted = true;
}

template<typename T>
void Timer<T>::stop() {
  _isStarted = false;
}

template<typename T>
bool Timer<T>::isStarted() {
  return _isStarted;
}

template<typename T>
void Timer<T>::done() {
  _isStarted = false;
  // Serial.println("Timer is done");
}

template<typename T>
void Timer<T>::handle(Clock *clock) {
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