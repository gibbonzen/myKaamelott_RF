#ifndef TimerUtils_h
#define TimerUtils_h

#include <stdint.h>

class TimerUtils {
  public:
    enum Unit { HOUR, MINUTE, SECOND, MILLISECOND };
    static uint64_t superMillis();
    static long convert(long time, Unit from, Unit to = TimerUtils::MILLISECOND);
    static int* toHMS(long time);
  private: 
    static uint64_t _finalMillis;
};

#endif