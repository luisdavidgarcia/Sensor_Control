#include "sw520d_tilt_sensor.hpp"

bool SW520D_Tilt_Sensor::isThereTilt()
{
  return digitalRead(pinNumber_) != 0;
}
