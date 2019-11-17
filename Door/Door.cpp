#include "Door.h"
#include "GPIO.h"
#include "DualOutputDevice.h"
#include "Clock.h"
#include "Timer.h"
//#include <Arduino.h>

Door::Door(int openPin, int closePin) : DualOutputDevice(GPIO(openPin), GPIO(closePin)) {
}

void Door::open() {
  if(_activityTimer->isStarted()) return;
  //_g.impulse();  // Deprecated : impulse is blocking
  _activityTimer->setCallback((&GPIO::disable), &_g);
  _g.enable();
  _activityTimer->start();
}

void Door::close() {
  if(_activityTimer->isStarted()) return;
  // _p.impulse();
  _activityTimer->setCallback(&GPIO::disable, &_p);
  _p.enable();
  _activityTimer->start();
}

void Door::stop() {
  if(_activityTimer->isStarted()) { // action in progress
    _p.disable();
    _g.disable();
    _activityTimer->stop();
  }
}

void Door::attach(Clock *clock) {
  _activityTimer = new Timer(40000);
  clock->attach(_activityTimer);
}
