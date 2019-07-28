#include "Door.h"
#include "GPIO.h"
#include "DualOutputDevice.h"
#include "Clock.h"
#include "Timer.h"
// #include <Arduino.h>

Door::Door(int openPin, int closePin) : DualOutputDevice(GPIO(openPin), GPIO(closePin)) {
}

void Door::open() {
  // Serial.println("OPEN");
  //_g.impulse();  // Deprecated : impulse is blocking
  _activityTimer->setCallback((&GPIO::disable), &_g);
  _g.enable();
  _activityTimer->start();
}

void Door::close() {
  // _p.impulse();
  _activityTimer->setCallback(&GPIO::disable, &_p);
  _p.enable();
  _activityTimer->start();
}

void Door::attach(Clock *clock) {
  _activityTimer = new Timer(35000);
  clock->attach(_activityTimer);
}
