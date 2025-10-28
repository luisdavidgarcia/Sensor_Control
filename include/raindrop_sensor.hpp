#ifndef RAINDROP_SENSOR_HPP
#define RAINDROP_SENSOR_HPP

#include <wiringPi.h>

class Raindrop_Sensor
{
public:
  Raindrop_Sensor(int pinNumber) : pinNumber_(pinNumber) 
  {
    pinMode(pinNumber_, INPUT);
  }
  bool isThereWater();
  
private:
  int pinNumber_;
};

#endif // RAINDROP_SENSOR_HPP
