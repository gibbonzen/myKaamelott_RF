#include "Door.h"
#include "../GPIO/GPIO.h"
#include "../OutputDevice/DualOutputDevice.h"
#include "../../Clock/Clock.h"
#include "../../Clock/Timer.h"

#include <iostream>

Door::Door(int openPin, int closePin) : DualOutputDevice(GPIO(openPin), GPIO(closePin)) {
  if(isReady()) {
    std::cout << "Door is ready" << std::endl;
  }
}

void Door::open() {
  //_g.impulse();  // Deprecated : impulse is blocking
  _activityTimer->setCallback((&GPIO::disable), &_g);
  _g.enable();
  _activityTimer->start();

  std::cout << "Door is opened" << std::endl;
}

void Door::close() {
  // _p.impulse();
  _activityTimer->setCallback(&GPIO::disable, &_p);
  _p.enable();
  _activityTimer->start();

  std::cout << "Door is closed" << std::endl;
}

void Door::attach(Clock *clock) {
  _activityTimer = new Timer(5000);
  clock->attach(_activityTimer);
}

void execute() {
  std::cout << "Disabled is called" << std::endl;
}