#ifndef DOOR_SERVICE_H
#define DOOR_SERVICE_H

#include "OnActionEvent.h"
#include "Door.h"
#include "DoorCounter.h"
#include "State.h"
#include "DoorState.h"

class DoorService : public OnActionEvent<DoorActionEvent> {
  public:
    DoorService(Door*, Clock*);
    void setState(State*);
    void onEvent(DoorActionEvent*);
    void next();
    void resetNext();
    void after(int delay);
    void emit();

  private:
    Door *door_ = 0;
    Clock *clock_ = 0;
    DoorCounter *counter_ = 0;
    State* states_[5];
    StateMachine *machine_ = 0;
    Timer<DoorService> *timer_ = 0;
};

DoorService::DoorService(Door *door, Clock *clock) {
  door_ = door;
  clock_ = clock;
  counter_ = new DoorCounter(clock_, 40000);
  Serial.println("State machine initialized...");
  machine_ = new StateMachine();
  DoorActionListener *listener = new DoorActionListener(this);
  door->onActionPerformed(listener);

  //////////////
  /// STATES ///
  //////////////
  State *CLOSED  = new State(DoorState::CLOSED);
  DualState *OPENING = new DualState(DoorState::OPENING);
  State *OPENED  = new State(DoorState::OPENED);
  DualState *CLOSING = new DualState(DoorState::CLOSING);
  State *CLOSING_STOPPED = new State(DoorState::CLOSING_STOPPED);
  State *OPENING_STOPPED = new State(DoorState::OPENING_STOPPED);

  CLOSED->setNext(OPENING);
  OPENED->setNext(CLOSING);

  OPENING->setNext(OPENED);
  OPENING->setSecond(OPENING_STOPPED);

  CLOSING->setNext(CLOSED);
  CLOSING->setSecond(CLOSING_STOPPED);

  CLOSING_STOPPED->setNext(OPENING);
  OPENING_STOPPED->setNext(CLOSING);

  states_[0] = CLOSED;
  states_[1] = OPENING;
  states_[2] = OPENED;
  states_[3] = CLOSING;
  states_[3] = CLOSING_STOPPED;
  states_[4] = OPENING_STOPPED;

  setState(CLOSED);
}

void DoorService::setState(State* state) {
  machine_->setCurrent(state);
}

void DoorService::onEvent(DoorActionEvent* evt) {
  // std::cout << "Event <" << evt->getEvent() << "> catch by DoorService" << std::endl;
  switch (evt->getObject()) {
    case DoorAction::OPEN:
    {
      Serial.println("Action <OPEN>");
      counter_->start();
      int in[] = { DoorState::CLOSED, DoorState::CLOSING_STOPPED };
      if(machine_->in(in, 2)) {
        next();
        after(counter_->getRemainingTime());
      }
    }
    break;

    case DoorAction::CLOSE:
    {
      Serial.println("Action <CLOSE>");
      counter_->start();
      int in[] = { DoorState::OPENED, DoorState::OPENING_STOPPED };
      if(machine_->in(in, 2)) {
        next();
        after(counter_->getRemainingTime());
      }
    }
    break;

    case DoorAction::STOP:
    {
      Serial.println("Action <STOP>");
      counter_->stop();
      timer_->stop();
      machine_->second();
      emit();
    }
    break;
  }
}

void DoorService::next() {
  machine_->next();
  emit();
}

void DoorService::resetNext() {
  counter_->reset();
  next();
}

void DoorService::after(int delay) {
  Serial.print("Delay: ");
  Serial.println(delay);

  timer_ = new Timer<DoorService>(delay);
  clock_->attach(timer_);
  timer_->setCallback(&DoorService::resetNext, this);
  timer_->start();
}

void DoorService::emit() {
  Serial.print("code: ");
  Serial.println(machine_->getCurrent()->getCode());
}

#endif
