#ifndef DOOR_STATE_H
#define DOOR_STATE_H

enum DoorState {
  CLOSED           = 0b0000,
  OPENING          = 0b0001,
  OPENING_STOPPED  = 0b0010,
  OPENED           = 0b0011,
  CLOSING          = 0b0100,
  CLOSING_STOPPED  = 0b0101
};

#endif