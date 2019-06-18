#ifndef Counter_h
#define Counter_h

class Counter {
  public:
    static void increment();
    static unsigned long millis();

  private:
    static unsigned long _millis;
};

#endif