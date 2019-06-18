#include <iostream>
#include <windows.h>

#include "lib/Counter/Counter.h"

using namespace std;

void loop() {
  Counter::increment();
  cout << Counter::millis() << endl;

}

int main(int argc, char* argv[])
{
  while(true) {
    loop();

    Sleep(1);
  }

  return 0;
}
