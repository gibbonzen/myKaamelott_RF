#include <iostream>
#include <windows.h>

#include "lib/Counter/Counter.h"
#include "lib/Clock/Clock.h"

using namespace std;

int time[3];
Clock clock(time);

void loop() {
  // Increment counters
  Counter::increment();
  clock.process();

  cout << clock.getTime() << endl;

}

int main(int argc, char* argv[])
{
  time[0] = 17;
  time[1] = 0;
  time[2] = 0;

  clock.setTime(time);

  while(true) {
    loop();
    Sleep(1);
  }

  return 0;
}
