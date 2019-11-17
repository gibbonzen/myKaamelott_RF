#ifndef RadioEventHandler_h
#define RadioEventHandler_h

#include "RadioHandler.h"
#include <Arduino.h>

template<typename T>
class RadioEventHandler : public RadioHandler {
    public:
        RadioEventHandler(uint8_t id, uint8_t cmdID, void (*cb)(T));
        void handle(uint32_t milli, uint8_t destID, uint8_t *buf);
        
    private:
        uint8_t id_ = 0;
        uint32_t lastRec_ = 0;
        uint8_t cmdID_ = 0;
        void execute(T cmd);
        void (*cb_)(T);
};

template<typename T>
RadioEventHandler<T>::RadioEventHandler(uint8_t id, uint8_t cmdID, void (*cb)(T)) {
    id_ = id;
    cmdID_ = cmdID;
    cb_ = cb;
}

template<typename T>
void RadioEventHandler<T>::handle(uint32_t milli, uint8_t destID, uint8_t *buf) {
    if(destID == id_)  {

        // if(milli - lastRec_ < 2000) { // Last receive less 200ms
        //     lastRec_ = milli;
        //     Serial.println("Command refused");
        //     return;
        // }
        
        // Serial.println("Event consumed");
        T cmd;
        memcpy(&cmd, buf, sizeof(cmd));
        execute(cmd);
        lastRec_ = milli;
    }

}

template<typename T>
void RadioEventHandler<T>::execute(T cmd) {
    if(cmdID_ == cmd.cmd) {
        cb_(cmd);
    }
}

#endif