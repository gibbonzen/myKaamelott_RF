#include <Arduino.h>


enum RadioCommand {
    OPEN = 0,
    CLOSE = 1,
    STOP = 2,
    SET_OPEN = 3,
    SET_CLOSE = 4,
    SET_TIME = 5
};

struct SimpleCommand {
    uint8_t from = 0;
    uint8_t to = 0;
    uint8_t cmd = 0;
};

struct ClockCommand : SimpleCommand {
    uint8_t y = 19;
    uint8_t M = 10;
    uint8_t d = 27;
    uint8_t h = 0;
    uint8_t m = 0;
    uint8_t s = 0;
};

struct DoorAutomateCommand : SimpleCommand {
    uint8_t h = 0;
    uint8_t m = 0;
    uint8_t s = 0;
    bool run = false;
};
