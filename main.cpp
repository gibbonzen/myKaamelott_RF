#include <iostream>
#include <windows.h>

#include "lib/Counter/Counter.h"
#include "lib/Clock/Clock.h"
#include "lib/Clock/ClockObserver.h"

using namespace std;

Clock clock(17, 0, 0);

long lastTime = clock.getTime();

void loop() {
  // Increment counters
  Counter::increment();
  clock.process();

  if(lastTime != clock.getTime()) { // each 1 sec 
    lastTime = clock.getTime();
     //clock.toString();
  }



}

void display() {
  cout << "test" << endl;
}

int main(int argc, char* argv[])
{
  ClockObserver openAt(&clock); // Open at 08:00 AM

  // void (*func)();
  // func = display;

  openAt.at(17, 0, 5, display);
  // openAt.start();

  while(true) {
    loop();
    Sleep(1);
  }

  return 0;
}
