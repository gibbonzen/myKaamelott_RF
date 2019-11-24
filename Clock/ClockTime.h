#ifndef CLOCK_TIME_H
#define CLOCK_TIME_H

#include <RTClib.h>
#include <TimerUtils.h>

class ClockTime {
  public:
    virtual DateTime now() = 0;
};

// RTC impl
class RTCTime : public ClockTime {
  public: 
    RTCTime(RTC_DS3231*);
    virtual DateTime now();
  
  private: 
    RTC_DS3231 *rtc_;
};

RTCTime::RTCTime(RTC_DS3231 *rtc) : rtc_(rtc) {
  Serial.println("Initialise RTCTime...");
}

DateTime RTCTime::now() {
  return rtc_->now();
}

// System impl
class SYSTime : public ClockTime {
  public: 
    SYSTime(uint16_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
    virtual DateTime now();

  private:
    void compute();
    uint16_t year_ = 2019;
    uint8_t month_ = 1;
    uint8_t day_ = 1;
    uint8_t hour_ = 1;
    uint8_t minute_ = 1;
    uint8_t second_ = 1;
    uint64_t millis_ = 0;
};

SYSTime::SYSTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second) :
  year_(year), month_(month), day_(day) { 
  // Month && year not managed
  // Serial.print("Initialise SYSTime: ");
  unsigned long hh = hour * 3600000L;
  unsigned long mm = minute * 60000L;
  unsigned long ss = second * 1000L;

  millis_ = hh + mm + ss;
}

void SYSTime::compute() {
  // Millis for start of arduino
  uint64_t ms = TimerUtils::superMillis();

  uint64_t millis = millis_ + ms;
  int* hms = TimerUtils::toHMS(millis);
  hour_ = hms[0];
  minute_ = hms[1];
  second_ = hms[2];
}

DateTime SYSTime::now() {
  compute();
  
  DateTime dt = DateTime(year_ , month_, day_, hour_, minute_, second_);
  // Serial.print("SYSTime time: ");
  // Serial.print(dt.hour());
  // Serial.print(":");
  // Serial.print(dt.minute());
  // Serial.print(":");
  // Serial.println(dt.second());

  return dt;
}

#endif