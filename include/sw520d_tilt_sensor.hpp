#ifndef SW520D_TILT_SENSOR_HPP
#define SW520D_TILT_SENSOR_HPP

#include <wiringPi.h>

class SW520D_Tilt_Sensor
{
public:
  SW520D_Tilt_Sensor(int pinNumber) : pinNumber_(pinNumber)
  {
    pinMode(pinNumber_, INPUT);
    pullUpDnControl(pinNumber_, PUD_UP);
  }
  bool isThereTilt();
private:
  int pinNumber_;
};

#endif // SW520D_TILT_SENSOR_HPP
