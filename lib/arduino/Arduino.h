#ifndef Arduino_h
#define Arduino_h

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1

class Arduino {
  public:
    static void pinMode(int pin, int mode);
    static void digitalWrite(int pin, int v);
    static int digitalRead(int pin);

    static void delay(int millis);
};

#endif