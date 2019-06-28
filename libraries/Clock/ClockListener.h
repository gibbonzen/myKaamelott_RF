#ifndef ClockListener_h
#define ClockListener_h

class Clock;

class ClockListener {
  public: 
    virtual void handle(Clock *clock) = 0;
};

#endif