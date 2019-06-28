#include <iostream>
#include <windows.h>

#include "lib/Counter/Counter.h"
#include "lib/Clock/Clock.h"
#include "lib/Clock/Timer.h"
#include "lib/Clock/ClockObserver.h"

#include "lib/Devices/Door/Door.h"

Clock clock(8, 0, 0);
Door door(1, 2);

long lastTime = clock.getTime();

void loop() {
  // Increment counters
  Counter::increment();
  clock.process();

  if(lastTime != clock.getTime()) { // each 1 sec 
    lastTime = clock.getTime();
     clock.toString();
  }

  
}

void display() {
  std::cout << "test display timer" << std::endl;
}

void reset() {
  std::cout << "Reset timer" << std::endl;
  clock.setTime(8);
}

void openDoor() {
  door.open();
}

void closeDoor() {
  door.close();
}

int main(int argc, char* argv[]) {
  ClockObserver resetAt(&clock); // Reset timer
  resetAt.at(8, 0, 30, reset);
  resetAt.start();

  door.attach(&clock);

  ClockObserver *openDoorAt = new ClockObserver(&clock);
  openDoorAt->at(8, 0, 10, openDoor);
  openDoorAt->start();
  
  ClockObserver closeDoorAt(&clock);
  closeDoorAt.at(8, 0, 20, closeDoor);
  closeDoorAt.start();


  while(true) {
    loop();
    Sleep(1);
  }

  return 0;
}
