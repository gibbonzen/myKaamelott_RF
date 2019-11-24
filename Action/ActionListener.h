#ifndef ACTION_LISTENER_H
#define ACTION_LISTENER_H

#include "ActionEvent.h"

template<typename T>
class ActionListener {
  public:
    virtual void actionPerformed(ActionEvent<T>*) = 0;
};

#endif