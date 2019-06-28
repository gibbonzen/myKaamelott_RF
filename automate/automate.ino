#include <Clock.h>
#include <ClockListener.h>
#include <ClockObserver.h>
#include <Door.h>
#include <TimerUtils.h>

Clock clock(8, 0, 0);
Door door(1, 2);

void open() {
  door.open();
}

void close() {
  door.close();
}

void reset() {
  clock.setTime(8);
}

void setup() {
  door.attach(&clock); // La porte a besoin d'un timer interne basé sur l'horloge
  
  ClockObserver *openTask = new ClockObserver(&clock);
  openTask->at(8, 0, 10, open);
  openTask->start();

  ClockObserver *closeTask = new ClockObserver(&clock);
  closeTask->at(8, 0, 20, close);
  openTask->start();

  ClockObserver *resetTask = new ClockObserver(&clock);
  resetTask->at(8, 0, 30, reset);
  resetTask->start();
}

void loop() {
  clock.process();
}
