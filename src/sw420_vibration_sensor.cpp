#include "sw420_vibration_sensor.hpp"

bool SW420_Vibration_Sensor::isThereVibration() 
{
  return static_cast<bool>(digitalRead(pinNumber_));
}
