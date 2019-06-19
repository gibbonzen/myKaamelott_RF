#include "TimerUtils.h"

#include "../Counter/Counter.h"

#define SIMPLE_MULTIPLICATOR 60
#define SEC_MILLIS_MULTIPLICATOR 1000

#define DOWN_CONVERT '*' // Hour to minutes or seconds
#define UP_CONVERT '/' // seconds to minutes or hour

/** 
 * Retourne le nombre de millisecondes depuis le démarrage du programme.
 *
 * @return Le nombre de millisecondes depuis le démarrage du programme sous la forme d'un
 * nombre entier sur 64 bits (unsigned long long).
 */
unsigned long long TimerUtils::superMillis() {
  static unsigned long nbRollover = 0;
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = Counter::millis();

  if (currentMillis < previousMillis) {
    nbRollover++;
  }
  previousMillis = currentMillis;

  unsigned long long finalMillis = nbRollover;
  finalMillis <<= 32;
  finalMillis +=  currentMillis;
  return finalMillis;
}

long TimerUtils::convert(int time, Unit from, Unit to) {
  int multiplicator = SIMPLE_MULTIPLICATOR;
  int direction = DOWN_CONVERT;

  switch(from) {
    case TimerUtils::HOUR: 
      // MINUTE : h / 60
      if(to == TimerUtils::SECOND) multiplicator *= SIMPLE_MULTIPLICATOR; // h / (60 * 60)
      if(to == TimerUtils::MILLISECOND) multiplicator *= SIMPLE_MULTIPLICATOR * SEC_MILLIS_MULTIPLICATOR; // h / (60 * 60 * 1000)
      break;

    case TimerUtils::MINUTE: 
      if(to == TimerUtils::HOUR) direction = UP_CONVERT; // m * 60
      // SECOND : m / 60
      if(to == TimerUtils::MILLISECOND) multiplicator *= SEC_MILLIS_MULTIPLICATOR; // m / (60 * 1000)
      break;

    case TimerUtils::SECOND:
      if(to == TimerUtils::HOUR) {
          direction = UP_CONVERT;
          multiplicator *= SIMPLE_MULTIPLICATOR; // s * (60 * 60)
      }
      // MINUTE : s * 60
      if(to == TimerUtils::MILLISECOND) multiplicator = SEC_MILLIS_MULTIPLICATOR ; // s * (60 * 1000)
      break;
    case TimerUtils::MILLISECOND:
      direction = UP_CONVERT;
      if(to == TimerUtils::SECOND) multiplicator = SEC_MILLIS_MULTIPLICATOR; // ms * 1000
      if(to == TimerUtils::MINUTE) multiplicator *= SEC_MILLIS_MULTIPLICATOR; // ms * (60 * 1000)
      if(to == TimerUtils::HOUR) multiplicator *= SIMPLE_MULTIPLICATOR * SEC_MILLIS_MULTIPLICATOR; // ms * (60 * 60 * 1000)
      break;
  }

  int result = time * multiplicator;
  if(direction == UP_CONVERT) result = time / multiplicator;
  return result;
}