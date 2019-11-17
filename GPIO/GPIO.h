#ifndef GPIO_h
#define GPIO_h

class GPIO {
  public:
    GPIO();
    GPIO(int pin);
    void setMode(int mode);
    void enable();
    void disable();
    void impulse(int millis = 200);
    bool isReady();

  private:
    int _pin;
    bool _isReady;
};

#endif