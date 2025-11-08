#include "sw420_vibration_sensor.hpp"
#include <iostream>

bool SW420_Vibration_Sensor::isThereVibration() 
{
  // 0 indicates that there is a vibration
  std::cout << digitalRead(pinNumber_) << "\n";
  return digitalRead(pinNumber_) == 0;
}
