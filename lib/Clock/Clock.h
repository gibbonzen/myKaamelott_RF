#ifndef Clock_h
#define Clock_h

#include "../TimerUtils/TimerUtils.h"
#include <vector>
#include "ClockListener.h"

// class ClockObserver;

class Clock {
    public:
        Clock(int h, int m, int s);
        void setTime(int h = 0, int m = 0, int s = 0);
        long getTime(TimerUtils::Unit unit = TimerUtils::MILLISECOND);
        void process();
        void attach(ClockListener *obs);
        void handle();
        void toString();

    private:
        int _hCount;
        int _mCount;
        int _sCount;
        std::vector<ClockListener*> _observers;
};

#endif