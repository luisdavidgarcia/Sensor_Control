#include "sw420_vibration_sensor.hpp"

bool SW420_Vibration_Sensor::isThereVibration() 
{
  return digitalRead(pinNumber_);
}
