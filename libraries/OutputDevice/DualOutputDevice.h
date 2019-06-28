#ifndef DualOutputDevice_h
#define DualOutputDevice_h

#include "GPIO.h"

class DualOutputDevice {
  public:
    DualOutputDevice(GPIO g, GPIO p);
    bool isReady();

  protected:
    GPIO _g;
    GPIO _p;
};

#endif