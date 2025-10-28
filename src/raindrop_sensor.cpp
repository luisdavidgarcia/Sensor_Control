#include "raindrop_sensor.hpp"

bool Raindrop_Sensor::isThereWater() 
{
  return static_cast<bool>(digitalRead(pinNumber_));
}
