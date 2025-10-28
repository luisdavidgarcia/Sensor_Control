#include "raindrop_sensor.hpp"

bool Raindrop_Sensor::isThereWater() 
{
  return digitalRead(pinNumber_) != 0;
}
