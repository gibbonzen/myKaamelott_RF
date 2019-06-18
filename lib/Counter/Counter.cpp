#include "Counter.h"

void Counter::increment() {
  _millis++;
}

unsigned long Counter::millis() {
  return _millis;
}

unsigned long Counter::_millis = 0;