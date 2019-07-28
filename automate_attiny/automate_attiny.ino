// Compile "Internal 8Mhz"

#include <Clock.h>
#include <ClockObserver.h>
#include <Door.h>
#include <WatchDog.h>

#define OPEN 3
#define CLOSE 2

int h = 22;
int m = 5;
int s = 0;

Clock clock(h, m, s);
Door door(OPEN, CLOSE);

void open() {
  door.open();
}

void close() {
  door.close();
}

void reset() {
  clock.setTime(h, m);
}

void processClock() {
  clock.process();
}

void loop() {
}

void setup() {  
  reset();
  
  door.attach(&clock); // La porte a besoin d'un timer interne basé sur l'horloge
  
  ClockObserver *openTask = new ClockObserver(&clock);
  openTask->at(22, 10, 0, open);
  openTask->start();

  ClockObserver *closeTask = new ClockObserver(&clock);
  closeTask->at(22, 30, 0, close);
  closeTask->start();

/*  ClockObserver *resetTask = new ClockObserver(&clock);
  resetTask->at(21, 20, 0, reset);
  resetTask->start();*/

  WatchDog::init(processClock, OVF_1000MS);
}
