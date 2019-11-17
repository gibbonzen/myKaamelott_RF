#ifndef RadioHandler_h
#define RadioHandler_h

class RadioHandler {
  public:
    virtual void handle(uint32_t milli, uint8_t destID, uint8_t *buf);
};

#endif