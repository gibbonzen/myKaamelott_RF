#include "TimerUtils.h"

#include <stdlib.h>
#include <stdint.h>
#include <Arduino.h>
//#include "Counter.h"

#define SIMPLE_MULTIPLICATOR 60
#define SEC_MILLIS_MULTIPLICATOR 1000

#define DOWN_CONVERT '*' // Hour to minutes or seconds
#define UP_CONVERT '/' // seconds to minutes or hour

uint64_t TimerUtils::_finalMillis = 0;

/** 
 * Retourne le nombre de millisecondes depuis le démarrage du programme.
 *
 * @return Le nombre de millisecondes depuis le démarrage du programme sous la forme d'un
 * nombre entier sur 64 bits (unsigned long long).
 */
uint64_t TimerUtils::superMillis() {
  static unsigned long nbRollover = 0;
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();

  if (currentMillis < previousMillis) {
    nbRollover++;
  }
  previousMillis = currentMillis;

  unsigned long long finalMillis = nbRollover;
  finalMillis <<= 32;
  finalMillis +=  currentMillis;

  return finalMillis;

  // uint32_t current = millis();

  // if(current < TimerUtils::_finalMillis) {
  //   TimerUtils::_finalMillis += TimerUtils::_finalMillis - current;
  // }
  // else TimerUtils::_finalMillis = current;

  // return TimerUtils::_finalMillis;
}

long TimerUtils::convert(long time, Unit from, Unit to) {
  switch(from) {
    case TimerUtils::HOUR: 
      if(to == TimerUtils::MINUTE) return time * 60; // h * 60
      if(to == TimerUtils::SECOND) return time * 3600; // h * (60 * 60)
      if(to == TimerUtils::MILLISECOND) return time * 3600000; // h * (60 * 60 * 1000)
      break;

    case TimerUtils::MINUTE: 
      if(to == TimerUtils::HOUR) return time / 60; // m / 60
      if(to == TimerUtils::SECOND) return time * 60; // m * 60
      if(to == TimerUtils::MILLISECOND) return time * 60000; // m * (60 * 1000)
      break;

    case TimerUtils::SECOND:
      if(to == TimerUtils::HOUR) return time / 3600; // s * (60 * 60)
      if(to == TimerUtils::MINUTE) return time / 60;// s * 60
      if(to == TimerUtils::MILLISECOND) return time * 1000; // s * 1000
      break;
    case TimerUtils::MILLISECOND:
      if(to == TimerUtils::SECOND) return time / 1000; // ms / 1000
      if(to == TimerUtils::MINUTE) return time / 60000; // ms / (60 * 1000)
      if(to == TimerUtils::HOUR) return time / 3600000; // ms / (60 * 60 * 1000)
      break;
  }
  return 0;
}

int* TimerUtils::toHMS(long time) {
  int *hms = (int *) malloc(3 * sizeof(int));
  hms[0] = time / 3600000;
  hms[1] = (time % 3600000) / 60000;
  hms[2] = ((time % 3600000) % 60000) / 1000;
  return hms;
}