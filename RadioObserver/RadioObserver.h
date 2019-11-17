#ifndef RadioObserver_h
#define RadioObserver_h

#include "RadioHandler.h"

class RadioObserver {
    public:
        RadioObserver(int radioPin);
        void on(RadioHandler *handler);
        void listen(uint32_t milli, uint8_t *buf);

    private:
        int pin_ = 0;
        int sizeOf = 0;
        RadioHandler** handlers_ = 0;
};

RadioObserver::RadioObserver(int radioPin) {
    handlers_ = new RadioHandler*[10];
    pin_ = radioPin;
}

void RadioObserver::listen(uint32_t milli, uint8_t *buf) {
    for(int i = 0; i < sizeOf; i++) {
        RadioHandler *handler = handlers_[i];
        handler->handle(milli, buf[1], buf); // call observer handle method
    }
}

void RadioObserver::on(RadioHandler *handler) {
    handlers_[sizeOf] = handler;
    sizeOf++;
}

#endif