#ifndef SW420_VIBRATION_SENSOR_HPP
#define SW420_VIBRATION_SENSOR_HPP

#include <wiringPi.h>

class SW420_Vibration_Sensor
{
public:
  SW420_Vibration_Sensor(int pinNumber) : pinNumber_(pinNumber)
  {
    pinMode(pinNumber_, INPUT);
  }
  bool isThereVibration();
private:
  int pinNumber_;
};

#endif // SW420_VIBRATION_SENSOR_HPP
