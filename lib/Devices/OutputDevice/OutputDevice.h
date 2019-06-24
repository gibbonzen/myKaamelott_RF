#ifndef OutputDevice_h
#define OutputDevice_h

#include "../GPIO/GPIO.h"

class OutputDevice {
  public:
    OutputDevice(GPIO gpio);
    bool isReady();

  protected:
    GPIO _gpio;
};

#endif