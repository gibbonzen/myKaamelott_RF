#ifndef DOOR_COUNTER_H
#define DOOR_COUNTER_H

#include "Clock.h"

class DoorCounter {
  public:
    DoorCounter(Clock*, long);
    void start();
    void reset();
    void stop();
    unsigned long getRemainingTime();
    int getPercent();

  private:
    Clock* clock_ = 0;

    long duration_ = 0;
    bool reverse_ = false;

    unsigned long progress_ = 0;
    unsigned long endMillis_ = 0;

    unsigned long endTime_ = 0;
    unsigned long startTime_ = 0;
    unsigned long stopTime_ = 0;

    void computeReverse();
};

DoorCounter::DoorCounter(Clock* clock, long duration) {
  Serial.println("Initializing counter...");
  clock_ = clock;
  duration_ = duration;
  reset();
}

void DoorCounter::start() {
  startTime_ = clock_->milli();
  endTime_ = startTime_ + endMillis_;
}

void DoorCounter::reset() {
  endMillis_ = duration_;
  startTime_ = 0;
  stopTime_ = 0;
  reverse_ = false;
}

void DoorCounter::stop() {
  stopTime_ = clock_->milli();
  computeReverse();
}

void DoorCounter::computeReverse() {
  reverse_ = !reverse_;
  if(reverse_) {
    // compute time between start and stop
    progress_ = stopTime_ - startTime_;
    endMillis_ = progress_;
    
    Serial.print("Millis to go to left:");
    Serial.println(endMillis_);
  }
  else {
    // endMillis contain time to got to start
    // compute time between start and stop
    progress_ = stopTime_ - startTime_;

    // substract local progress to endMillis
    endMillis_ -= progress_;

    // duration is actionDuration - endMillis
    endMillis_ = duration_ - endMillis_;
    
    Serial.print("Millis to go to right:");
    Serial.println(endMillis_);
  }
}

unsigned long DoorCounter::getRemainingTime() {
  if(startTime_ == 0) return 0;

  unsigned long now = clock_->milli();
  unsigned long remaining = abs(endTime_ - now);
  return remaining;
}

int DoorCounter::getPercent() {
  unsigned long remaining = endMillis_ - getRemainingTime();
  int percent = remaining / endMillis_ * 100;
  return percent;
}

#endif