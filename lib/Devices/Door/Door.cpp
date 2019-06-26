#include "Door.h"
#include "../GPIO/GPIO.h"
#include "../OutputDevice/DualOutputDevice.h"
#include "../../Clock/Clock.h"
#include "../../Clock/Timer.h"

#include <iostream>
#include <functional>

using namespace std;

Door::Door(int openPin, int closePin) : DualOutputDevice(GPIO(openPin), GPIO(closePin)) {
  if(isReady()) {
    cout << "Door is ready" << endl;
  }
}

void Door::open() {
  //_g.impulse();  // Deprecated : impulse is blocking
  _activityTimer->setCallback(std::bind(&GPIO::disable, _g));
  _g.enable();
  _activityTimer->start();

  cout << "Door is opened" << endl;
}

void Door::close() {
  // _p.impulse();
  _activityTimer->setCallback(std::bind(&GPIO::disable, _p));
  _p.enable();
  _activityTimer->start();

  cout << "Door is closed" << endl;
}

void Door::attach(Clock *clock) {
  _activityTimer = new Timer(5000);
  clock->attach(_activityTimer);
}