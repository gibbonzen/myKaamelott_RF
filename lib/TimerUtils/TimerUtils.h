#ifndef TimerUtils_h
#define TimerUtils_h

class TimerUtils {
  public:
    enum Unit { HOUR, MINUTE, SECOND, MILLISECOND };
    unsigned long long superMillis();
    long convert(int time, Unit from, Unit to);
};

#endif