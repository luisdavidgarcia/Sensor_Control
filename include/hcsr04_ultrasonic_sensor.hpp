#ifndef HCSRO4_ULTRASONIC_SENSOR_HPP
#define HCSR04_ULTRASONIC_SENSOR_HPP

#include <wiringPi.h>
#include <chrono>
#include <thread>

constexpr int speedOfSound_mmPs_k = 0.343;
constexpr std::chrono::seconds one_s_k{1};
constexpr std::chrono::microseconds two_us_k{2};
constexpr std::chrono::microseconds ten_us_k{10};

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
