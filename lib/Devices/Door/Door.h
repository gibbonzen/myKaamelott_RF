#ifndef Door_h
#define Door_h

#include "../OutputDevice/DualOutputDevice.h"
#include "../../Clock/Clock.h"
#include "../../Clock/Timer.h"

class Door : public DualOutputDevice {
  public:
    Door(int openPin, int closePin);
    void attach(Clock *clock);
    void open();
    void close();

  private:
    Timer *_activityTimer;
};

#endif