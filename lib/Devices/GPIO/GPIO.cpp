#include "GPIO.h"

#include "../../arduino/Arduino.h"

#include <iostream>

GPIO::GPIO() {
  _isReady = false;
}

GPIO::GPIO(int pin): GPIO() {
  _pin = pin;
}

void GPIO::setMode(int mode) {
  Arduino::pinMode(_pin, mode);
  _isReady = true;
}

void GPIO::enable() {
  std::cout << "GPIO n." << _pin << " enabled..." << std::endl; 
 Arduino:: digitalWrite(_pin, HIGH);
}

void GPIO::disable() {
  std::cout << "GPIO n." << _pin << " disabled..." << std::endl; 
  Arduino::digitalWrite(_pin, LOW);
}

void GPIO::impulse(int millis) {
  enable();
  Arduino::delay(millis);
  disable();
  Arduino::delay(millis);
}

bool GPIO::isReady() {
  return _isReady;
}