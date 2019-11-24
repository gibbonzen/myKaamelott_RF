#ifndef DOOR_SERVICE_H
#define DOOR_SERVICE_H

#include "OnActionEvent.h"
#include "Door.h"
#include "State.h"
#include "DoorState.h"

class DoorService : public OnActionEvent<DoorActionEvent> {
  public:
    DoorService(Door*);
    void setState(State*);
    void onEvent(DoorActionEvent*);

  private:
    Door *door_ = 0;
    State* states_[5];
    StateMachine *machine_ = 0;
};

DoorService::DoorService(Door *door) {
  door_ = door;
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
      Serial.println("Action <OPEN>");
      break;

    case DoorAction::CLOSE:
      Serial.println("Action <CLOSE>");
      break;

    case DoorAction::STOP:
      Serial.println("Action <STOP>");
      break;
  }
}

#endif
