#include <iostream>
#include <windows.h>
#include <functional>

#include "lib/Counter/Counter.h"
#include "lib/Clock/Clock.h"
#include "lib/Clock/Timer.h"
#include "lib/Clock/ClockObserver.h"

#include "lib/Devices/Door/Door.h"

using namespace std;
using namespace std::placeholders;

Clock clock(8, 0, 0);

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
  cout << "test display timer" << endl;
}

void reset() {
  cout << "Reset timer" << endl;
  clock.setTime(8);
}

int main(int argc, char* argv[]) {
  ClockObserver resetAt(&clock); // Reset timer
  resetAt.at(8, 0, 30, reset);
  resetAt.start();

  Door door(1, 2);
  door.attach(&clock);

  ClockObserver *openDoorAt = new ClockObserver(&clock);
  openDoorAt->at(8, 0, 10, std::bind(&Door::open, door));
  openDoorAt->start();
  
  ClockObserver closeDoorAt(&clock);
  closeDoorAt.at(8, 0, 20, std::bind(&Door::close, door));
  closeDoorAt.start();


  while(true) {
    loop();
    Sleep(1);
  }

  return 0;
}
