#include "GPIO.h"
#include <Arduino.h>

GPIO::GPIO() {
  _isReady = false;
}

GPIO::GPIO(int pin): GPIO() {
  _pin = pin;
}

void GPIO::setMode(int mode) {
  pinMode(_pin, mode);
  _isReady = true;
}

void GPIO::enable() {
  digitalWrite(_pin, HIGH);
}

void GPIO::disable() {
  digitalWrite(_pin, LOW);
}

void GPIO::impulse(int millis) {
  enable();
  delay(millis);
  disable();
  delay(millis);
}

bool GPIO::isReady() {
  return _isReady;
}