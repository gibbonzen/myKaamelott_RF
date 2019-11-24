#ifndef ACTION_EVENT_H
#define ACTION_EVENT_H

template<typename T>
class ActionEvent {
  public:
    ActionEvent(String evt, T obj);
    String getEvent();
    T getObject();

  private:
    String evt_;
    T obj_;
};

template<typename T>
ActionEvent<T>::ActionEvent(String evt, T obj) : evt_(evt), obj_(obj) { }

template<typename T>
String ActionEvent<T>::getEvent() {
  return evt_;
}

template<typename T>
T ActionEvent<T>::getObject() {
  return obj_;
}

#endif