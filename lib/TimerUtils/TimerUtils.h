#ifndef TimerUtils_h
#define TimerUtils_h

class TimerUtils {
  public:
    enum Unit { HOUR, MINUTE, SECOND, MILLISECOND };
    static unsigned long long superMillis();
    static long convert(int time, Unit from, Unit to);
};

#endif