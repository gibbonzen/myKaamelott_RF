#include <iostream>
#include <windows.h>

#include "lib/Counter/Counter.h"
#include "lib/Clock/Clock.h"
#include "lib/Clock/ClockObserver.h"

using namespace std;

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
  cout << "test" << endl;
}

void reset() {
  cout << "Reset timer" << endl;
  clock.setTime(8);
}

int main(int argc, char* argv[]) {
  ClockObserver openAt(&clock); // Open at 08:00:05 AM
  openAt.at(8, 0, 2, display);
  openAt.start();

  ClockObserver closeAt(&clock); // Close at 08:00:10
  closeAt.at(8, 0, 5, reset);
  closeAt.start();


  while(true) {
    loop();
    Sleep(1);
  }

  return 0;
}
