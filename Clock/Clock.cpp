#include "Clock.h"
#include "ClockListener.h"
#include <RTCLib.h>

Clock::Clock(RTC_DS3231 *rtc) {
    observers_ = new ClockListener*[5];
    rtc_ = rtc;
}

void Clock::setTime(DateTime time) {
    sCount_ = time.second();
    mCount_ = time.minute();
    hCount_ = time.hour();
}

void Clock::toMillis() {
    unsigned long hour = hCount_ * 3600000L;
    unsigned long min = mCount_ * 60000L;
    unsigned long sec = sCount_ * 1000L;
    millis_ = hour + min + sec; 
}

unsigned long Clock::milli() {
    toMillis();
    return millis_;
}

int Clock::hour() {
    return hCount_;
}

int Clock::minute() {
    return mCount_;
}

int Clock::second() {
    return sCount_;
}

bool Clock::isTime(int h, int m, int s) {
    return h == hCount_ && m == mCount_ && s == sCount_;
}

void Clock::process() {
    Clock::setTime(rtc_->now());

    // call handle method of observers
    handle();
}

void Clock::attach(ClockListener *obs) {
    // Add observer
    observers_[sizeOf_] = obs;
    sizeOf_++;
}

void Clock::handle() {
    for(int i = 0; i < sizeOf_; i++) {
        ClockListener *obs = observers_[i];
        obs->handle(this); // call observer handle method
    }
}