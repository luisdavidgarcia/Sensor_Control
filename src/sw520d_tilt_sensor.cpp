#include "sw520d_tilt_sensor.hpp"
#include <iostream>

bool SW520D_Tilt_Sensor::isThereTilt()
{
  return digitalRead(pinNumber_) == LOW;
}
