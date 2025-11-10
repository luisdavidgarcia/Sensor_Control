#include "sw420_vibration_sensor.hpp"
#include <iostream>

bool SW420_Vibration_Sensor::isThereVibration() 
{
  return digitalRead(pinNumber_) == LOW;
}
