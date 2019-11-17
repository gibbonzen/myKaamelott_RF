#include "InputDevice.h"

#include "GPIO.h"

InputDevice::InputDevice(GPIO gpio) {
  _gpio = gpio;
  _gpio.setMode(0);
}

bool InputDevice::isReady() {
  return _gpio.isReady();
}