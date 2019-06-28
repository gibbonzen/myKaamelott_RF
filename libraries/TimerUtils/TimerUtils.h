#ifndef TimerUtils_h
#define TimerUtils_h

class TimerUtils {
  public:
    enum Unit { HOUR, MINUTE, SECOND, MILLISECOND };
    static unsigned long long superMillis();
    static long convert(unsigned long time, Unit from, Unit to = TimerUtils::MILLISECOND);
    static int* toHMS(unsigned long time);
};

#endif