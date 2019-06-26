#include "Door.h"
#include "../GPIO/GPIO.h"

#include "../OutputDevice/DualOutputDevice.h"

#include <iostream>

using namespace std;

Door::Door(int openPin, int closePin) : DualOutputDevice(GPIO(openPin), GPIO(closePin)) {
  if(isReady()) {
    cout << "Door is ready" << endl;
  }
}

void Door::open() {
  _g.impulse();
  cout << "Door is opened" << endl;
}

void Door::close() {
  _p.impulse();
  cout << "Door is closed" << endl;
}