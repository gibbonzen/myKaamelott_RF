#ifndef ON_ACTION_EVENT_H
#define ON_ACTION_EVENT_H

template<typename T>
class OnActionEvent {
  public:
    virtual void onEvent(T*) = 0;
};

#endif