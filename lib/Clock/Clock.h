#ifndef Clock_h
#define Clock_h

#include "../TimerUtils/TimerUtils.h"
#include "../Clock/ClockObserver.h"

class Clock {
    public:
        Clock(int h, int m, int s);
        void setTime(int h, int m, int s);
        long getTime(TimerUtils::Unit unit = TimerUtils::MILLISECOND);
        void process();
        void attach(void (ClockObserver::*handle)());
        void toString();

    private:
        int _hCount;
        int _mCount;
        int _sCount;
};

#endif