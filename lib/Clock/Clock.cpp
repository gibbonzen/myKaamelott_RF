#include <iostream>
#include <stdio.h>

#include "Clock.h"
#include "../TimerUtils/TimerUtils.h"
#include <vector>

#include "ClockObserver.h"

using namespace std;

Clock::Clock(int h, int m, int s) {
    Clock::setTime(h, m, s);
}

void Clock::setTime(int h, int m, int s) {
    _hCount = h;
    _mCount = m;
    _sCount = s;
}

long Clock::getTime(TimerUtils::Unit unit) {
  long hour = TimerUtils::convert(_hCount, TimerUtils::HOUR, unit);
  long min = TimerUtils::convert(_mCount, TimerUtils::MINUTE, unit);
  long sec = TimerUtils::convert(_sCount, TimerUtils::SECOND, unit);
  return hour + min + sec;
}

void Clock::process() {
    unsigned long timer = TimerUtils::superMillis();

    if(timer % 1000 == 0) { // Each seconds
        _sCount++;
    }

    if(_sCount >= 60) { // one minute
        _mCount++;
        _sCount = 0; // reinitiate seconds counter
    }

    if(_mCount >= 60) { // one hour
        _hCount++;
        _mCount = 0;
    }

    if(_hCount >= 24) { // one day
        _hCount = 0;
    }

    handle();
}

void Clock::attach(ClockObserver *obs) {
    // Add observer
    _observers.push_back(obs);
}

void Clock::handle() {
    for(int i = 0; i < _observers.size(); i++) {
        ClockObserver *obs = _observers[i];
        obs->handle(); // call observer handle method
    }
}

void Clock::toString() {
    printf("%02i:%02i:%02i", _hCount, _mCount, _sCount);
    cout << endl;
}