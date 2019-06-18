#ifndef Clock_h
#define Clock_h

#include "../TimerUtils/TimerUtils.h"

class Clock {
    public:
        Clock();
        Clock(int time[3]);
        void setTime(int time[3]);
        long getTime();
        void process();
        void toString();

    private:
        int _hCount;
        int _mCount;
        int _sCount;
};

#endif