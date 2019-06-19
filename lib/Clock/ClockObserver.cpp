#include "ClockObserver.h"
#include "Clock.h"

ClockObserver::ClockObserver(Clock *clock) {
  _clock = clock;
}

ClockObserver::~ClockObserver() {
  delete _clock;
}

void ClockObserver::at(int const& hour, int const& min, int const&sec, void (*func)()) {
  _hour = hour;
  _min = min;
  _sec = sec;
  _func = func;
}

void ClockObserver::start() {
  _isStarted = true;
}

void ClockObserver::stop() {
  _isStarted = false;
}

void ClockObserver::listen() {
  // Stopped
  if(!_isStarted) return;

  _func();
}