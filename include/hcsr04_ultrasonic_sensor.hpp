#ifndef HCSRO4_ULTRASONIC_SENSOR_HPP
#define HCSR04_ULTRASONIC_SENSOR_HPP

#include <wiringPi.h>

class HCSR04_Ultrasonic_Sensor
{
public:
  HCSR04_Ultrasonic_Sensor(int triggerPinNumber, int echoPinNumber) :
    triggerPinNumber_(triggerPinNumber), echoPinNumber_(echoPinNumber)
  {
    pinMode(triggerPinNumber_, OUTPUT);
    pinMode(echoPinNumber_, INPUT);
  }
  float getDistance_m();
private:
  int triggerPinNumber_;
  int echoPinNumber_;

  float getPulseDuration_s();
};

#endif // HCSRO4_ULTRASONIC_SENSOR_HPP
