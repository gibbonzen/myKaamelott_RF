#ifndef Door_h
#define Door_h

#include "../OutputDevice/OutputDevice.h"

class Door : public OutputDevice {
  public:
    Door(int pin);
    void open();
    void close();

  private:

};

#endif