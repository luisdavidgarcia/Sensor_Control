#include "hcsr04_ultrasonic_sensor.hpp"

float HCSR04_Ultrasonic_Sensor::getPulseDuration_s()
{
  float pulse_start{};
  while (digitalRead(echoPinNumber_) == 0)
  {
    pulseStart = // get current time
  }

  float pulse_end{};
  while(digitalRead(echoPinNumber_) == 1)
  {
    pulseEnd = // get current time
  }
  
  return pulseEnd - pulseStart;
}

float HCSR04_Ultrasonic_Sensor::getDistance_m()
{
  digitalWrite(triggerPinNumber_, LOW);
  // Delay 2 microseconds
  digitalWrite(triggerPinNumber_, HIGH);
  // Delay 10 microseconds
  digitalWrite(triggerPinNumber_, LOW);

  float duration = getPulseDuration_s();

  // Speed of sound in m/s divided in half because of roundtrip-time
  float distance = (duration * 0.343) / 2;
}
