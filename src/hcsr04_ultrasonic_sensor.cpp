#include "hcsr04_ultrasonic_sensor.hpp"

float HCSR04_Ultrasonic_Sensor::getPulseDuration_s()
{
  std::chrono::time_point<std::chrono::system_clock> pulse_start;
  std::chrono::time_point<std::chrono::system_clock> pulse_end;

  while (digitalRead(echoPinNumber_) == 0)
  {
    pulseStart = std::chrono::system_clock::now();
  }

  while(digitalRead(echoPinNumber_) == 1)
  {
    pulseEnd = std::chrono::system_clock::now();
  }
  
  return static_cast<float>((pulseEnd - pulseStart) / one_s_k);
}

float HCSR04_Ultrasonic_Sensor::getDistance_mm()
{
  digitalWrite(triggerPinNumber_, LOW);
  std::this_thread::sleep_for(two_us_k);
  digitalWrite(triggerPinNumber_, HIGH);
  std::this_thread::sleep_for(ten_us_k);
  digitalWrite(triggerPinNumber_, LOW);

  float duration = getPulseDuration_s();

  // Speed of sound in m/s divided in half because of roundtrip-time
  float distance = (duration * speedOfSound_mmPs_k) / 2;
}
