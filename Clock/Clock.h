#ifndef Clock_h
#define Clock_h

#include "TimerUtils.h"
#include "ClockListener.h"
#include <RTCLib.h>

class Clock {
    public:
        Clock(RTC_DS3231 *rtc);
        void setTime(DateTime time);
        void toMillis();
        unsigned long milli();
        int hour();
        int minute();
        int second();
        bool isTime(int h = 0, int m = 0, int s = 0);
        void process();
        void attach(ClockListener *obs);
        void handle();

    private:
        RTC_DS3231 *rtc_;
        int hCount_;
        int mCount_;
        int sCount_;
        unsigned long millis_;
        ClockListener** observers_ = 0;
        int sizeOf_ = 0;
};

#endif