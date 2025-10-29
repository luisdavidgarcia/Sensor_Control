#ifndef HCSRO4_ULTRASONIC_SENSOR_HPP
#define HCSR04_ULTRASONIC_SENSOR_HPP

#include <wiringPi.h>
#include <chrono>
#include <thread>

static const int speedOfSound_mmPs_k = 0.343;
static const one_s_k std::chrono::seconds{1};
static const two_us_k std::chrono::microseconds{2};
static const ten_us_k std::chrono::microseconds{10};

class HCSR04_Ultrasonic_Sensor
{
public:
  HCSR04_Ultrasonic_Sensor(int triggerPinNumber, int echoPinNumber) :
    triggerPinNumber_(triggerPinNumber), echoPinNumber_(echoPinNumber)
  {
    pinMode(triggerPinNumber_, OUTPUT);
    pinMode(echoPinNumber_, INPUT);
  }
  float getDistance_mm();
private:
  int triggerPinNumber_;
  int echoPinNumber_;

  float getPulseDuration_s();
};

#endif // HCSRO4_ULTRASONIC_SENSOR_HPP
