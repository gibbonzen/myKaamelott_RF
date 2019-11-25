#ifndef STATE_H
#define STATE_H

class State {
  public: 
    State(int);
    void setNext(State*);
    State* getNext();
    int getCode();

  private:
    int code_;
    State* next_ = 0;
};

// Impl
State::State(int code) : code_(code) { }

int State::getCode() {
  return code_;
}

void State::setNext(State *next) {
  next_ = next;
}

State* State::getNext() {
  return next_;
}

////////////////////////////////////

class DualState : public State {
  public: 
    DualState(int);
    void setSecond(State*);
    State* getSecond();

  private:
    State* second_ = 0;
};

// Impl
DualState::DualState(int code) : State(code) { }

void DualState::setSecond(State* second) {
  second_ = second;
}

State* DualState::getSecond() {
  return second_;
}

////////////////////////////////////

class StateMachine {
  public:
    void setCurrent(State*);
    State* getCurrent();
    void next();
    void second();
    bool in(int*, int);

  private:
    State *current_ = 0;
};

// Impl
void StateMachine::setCurrent(State *current) {
  current_ = current;
}

State* StateMachine::getCurrent() {
  return current_;
}
 
void StateMachine::next() {
  setCurrent(current_->getNext());
}

void StateMachine::second() {
  setCurrent(reinterpret_cast<DualState*>(current_));
}

bool StateMachine::in(int* expected, int size) {
  for(int i = 0; i < size; i++) {
    if(expected[i] == getCurrent()->getCode()) 
      return true;
  }
  return false;
}

#endif