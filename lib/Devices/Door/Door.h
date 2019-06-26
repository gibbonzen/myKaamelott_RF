#ifndef Door_h
#define Door_h

#include "../OutputDevice/DualOutputDevice.h"

class Door : public DualOutputDevice {
  public:
    Door(int openPin, int closePin);
    void open();
    void close();
};

#endif