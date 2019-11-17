#ifndef Door_h
#define Door_h

#include "DualOutputDevice.h"
#include "Clock.h"
#include "Timer.h"

class Door : public DualOutputDevice {
  public:
    Door(int openPin, int closePin);
    void attach(Clock *clock);
    void open();
    void close();
    void stop();

  private:
    Timer *_activityTimer;
};

#endif