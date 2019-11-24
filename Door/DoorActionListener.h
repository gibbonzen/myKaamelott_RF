#ifndef DOOR_ACTION_LISTENER_H
#define DOOR_ACTION_LISTENER_H

#include "ActionListener.h"
#include "OnActionEvent.h"
#include "DoorActionEvent.h"

//////////////////////////////////
//         DoorListener         //
//////////////////////////////////

class DoorActionListener : public ActionListener<DoorAction> {
  public:
    DoorActionListener(OnActionEvent<DoorActionEvent>*);
    virtual void actionPerformed(ActionEvent<DoorAction>*);
    virtual void actionPerformed(DoorActionEvent*);
  
  private:
    OnActionEvent<DoorActionEvent> *onEvt_ = 0;
};

DoorActionListener::DoorActionListener(OnActionEvent<DoorActionEvent> *onEvt) : ActionListener<DoorAction>() {
  onEvt_ = onEvt;
}

void DoorActionListener::actionPerformed(ActionEvent<DoorAction> *e) {
  actionPerformed(e);
}

void DoorActionListener::actionPerformed(DoorActionEvent *e) {
  // std::cout << "Execute action <" << e->getObject() << "> case by event <" << e->getEvent() << ">..." << std::endl;
  onEvt_->onEvent(e);
}


#endif