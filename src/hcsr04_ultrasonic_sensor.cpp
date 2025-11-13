#include "hcsr04_ultrasonic_sensor.hpp"

float HCSR04_Ultrasonic_Sensor::getPulseDuration_s()
{
  using clock = std::chrono::steady_clock;

  while (digitalRead(echoPinNumber_) == 0)
  {}
  auto pulseStart = clock::now();

  while(digitalRead(echoPinNumber_) == 1)
  {}
  auto pulseEnd = clock::now();

  const std::chrono::duration<float> pulseDuration = pulseEnd - pulseStart;

  return pulseDuration.count();
}

float HCSR04_Ultrasonic_Sensor::getDistance_cm()
{
  digitalWrite(triggerPinNumber_, LOW);
  std::this_thread::sleep_for(std::chrono::seconds{2});
  
  digitalWrite(triggerPinNumber_, HIGH);
  std::this_thread::sleep_for(ten_us_k);
  digitalWrite(triggerPinNumber_, LOW);

  float duration = getPulseDuration_s();

  // Speed of sound in cm/s divided in half because of roundtrip-time
  float distance = (duration * speedOfSound_cmPs_k) / 2.0f;

  return distance;
}
