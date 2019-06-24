#include "Door.h"
#include "../GPIO/GPIO.h"
#include "../OutputDevice/OutputDevice.h"

#include <iostream>

using namespace std;

Door::Door(int pin): OutputDevice(GPIO(pin)) {
  if(isReady()) {
    cout << "Door is ready" << endl;
  }
}

void Door::open() {
  _gpio.impulse();
  cout << "Door is opened" << endl;
}

void Door::close() {
  _gpio.impulse();
  cout << "Door is closed" << endl;
}