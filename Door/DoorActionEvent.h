#ifndef DOOR_ACTION_EVENT_H
#define DOOR_ACTION_EVENT_H

#include "ActionEvent.h"

enum DoorAction {
  OPEN,
  CLOSE,
  STOP
};

//////////////////////////////////
//        DoorActionEvent       //
//////////////////////////////////

class DoorActionEvent : public ActionEvent<DoorAction> {
  public:
    DoorActionEvent(String, DoorAction);
};

DoorActionEvent::DoorActionEvent(String evt, DoorAction act) : ActionEvent<DoorAction>(evt, act) { }

#endif