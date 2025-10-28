#ifndef SW520D_TILT_SENSOR_HPP
#define SW520D_TILT_SENSOR_HPP

#include <wiringPi.h>

class SW520D_Tilt_Sensor
{
public:
  SW520D_TiltSensor(int pinNumber) : pinNumber_(pinNumber)
  {
    pinMode(pinNumber_, INPUT);
  }
  bool isThereTilt();
private:
  int pinNumber_;
};

#endif // SW520D_TILT_SENSOR_HPP
