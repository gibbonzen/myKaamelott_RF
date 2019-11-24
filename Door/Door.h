#ifndef Door_h
#define Door_h

#include "DoorActionEvent.h"
#include "DoorActionListener.h"
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
    void onActionPerformed(DoorActionListener*);

  private:
    Timer *_activityTimer = 0;
    int size_ = 0;
    void emit(DoorAction);
    DoorActionListener** listeners_;
};


Door::Door(int openPin, int closePin) : DualOutputDevice(GPIO(openPin), GPIO(closePin)) {
  listeners_ = new DoorActionListener*[5];
}

void Door::onActionPerformed(DoorActionListener *listener)  {
  listeners_[size_] = listener;
  size_++;
}

void Door::open() {
  if(_activityTimer->isStarted()) return;
  //_g.impulse();  // Deprecated : impulse is blocking
  _activityTimer->setCallback((&GPIO::disable), &_g);
  _g.enable();
  _activityTimer->start();

  emit(DoorAction::OPEN);
}

void Door::close() {
  if(_activityTimer->isStarted()) return;
  // _p.impulse();
  _activityTimer->setCallback(&GPIO::disable, &_p);
  _p.enable();
  _activityTimer->start();

  emit(DoorAction::CLOSE);
}

void Door::stop() {
  if(_activityTimer->isStarted()) { // action in progress
    _p.disable();
    _g.disable();
    _activityTimer->stop();

    emit(DoorAction::STOP);
  }
}

void Door::emit(DoorAction action) {
  Serial.print("Door emit event <");
  Serial.print(action);
  Serial.println(">...");

  DoorActionEvent *evt = new DoorActionEvent("actionPerformed", action);
  for(int i = 0; i < size_; i++) {
    listeners_[i]->actionPerformed(evt);
  }
}

void Door::attach(Clock *clock) {
  _activityTimer = new Timer(40000);
  clock->attach(_activityTimer);
}

#endif