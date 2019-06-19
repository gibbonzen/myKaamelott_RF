#include <iostream>
#include <windows.h>

#include "lib/Counter/Counter.h"
#include "lib/Clock/Clock.h"

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

int main(int argc, char* argv[])
{

  while(true) {
    loop();
    Sleep(1);
  }

  return 0;
}
