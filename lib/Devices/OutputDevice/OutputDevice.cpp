#include "OutputDevice.h"

#include "../GPIO/GPIO.h"

OutputDevice::OutputDevice(GPIO gpio) {
  _gpio = gpio;
  _gpio.setMode(1);
}

bool OutputDevice::isReady() {
  return _gpio.isReady();
}