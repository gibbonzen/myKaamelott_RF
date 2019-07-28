#include "Clock.h"
#include "ClockListener.h"
#include "TimerUtils.h"
#include <Arduino.h>
#include <stdint.h>

Clock::Clock(int h, int m, int s) {
    _observers = new ClockListener*[5];
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

bool Clock::isTime(int h, int m, int s) {
    return h == _hCount && m == _mCount && s == _sCount;
}

void Clock::process() {
    _sCount++;

    // if(_millis >= 1000) { // Each seconds
    //     _millis = 0;        
    //     _sCount++;
    // }

    if(_sCount >= 60) { // one minute
        _sCount = 0; // reinitiate seconds counter
        _mCount++;
    }

    if(_mCount >= 60) { // one hour
        _mCount = 0;
        _hCount++;
    }

    if(_hCount >= 24) { // one day
        _hCount = 0;
    }

    handle();
}

void Clock::attach(ClockListener *obs) {
    // Add observer
    _observers[sizeOf] = obs;
    sizeOf++;
}

void Clock::handle() {
    for(int i = 0; i < sizeOf; i++) {
        ClockListener *obs = _observers[i];
        obs->handle(this); // call observer handle method
    }
}