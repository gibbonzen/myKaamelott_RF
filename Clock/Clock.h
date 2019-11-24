#ifndef CLOCK_H
#define CLOCK_H

#include "ClockListener.h"
#include "ClockTime.h"

class Clock {
    public:
        Clock(ClockTime*);
        void setTime(DateTime);
        void toMillis();
        unsigned long milli();
        uint8_t hour();
        uint8_t minute();
        uint8_t second();
        bool isTime(uint8_t, uint8_t, uint8_t);
        void process();
        void attach(ClockListener *obs);
        void handle();

    private:
        ClockTime *time_;
        uint8_t hCount_;
        uint8_t mCount_;
        uint8_t sCount_;
        unsigned long millis_;
        ClockListener** observers_ = 0;
        int sizeOf_ = 0;
};

///////////////////////////////////////

Clock::Clock(ClockTime *time) : time_(time) {
    observers_ = new ClockListener*[5];
    setTime(time_->now());
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

uint8_t Clock::hour() {
    return hCount_;
}

uint8_t Clock::minute() {
    return mCount_;
}

uint8_t Clock::second() {
    return sCount_;
}

bool Clock::isTime(uint8_t h, uint8_t m, uint8_t s) {
    return h == hCount_ && m == mCount_ && s == sCount_;
}

void Clock::process() {
    // Serial.println("Clock processing...");
    setTime(time_->now());

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

#endif