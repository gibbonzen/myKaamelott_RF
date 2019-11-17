#ifndef InputDevice_h
#define InputDevice_h

#include "GPIO.h"

class InputDevice {
  public:
    InputDevice(GPIO gpio);
    bool isReady();

  protected:
    GPIO _gpio;
};

#endif