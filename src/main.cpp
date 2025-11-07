#include <wiringPi.h>

#include "hcsr04_ultrasonic_sensor.hpp"
#include "raindrop_sensor.hpp"
#include "sg90_servo_motor.hpp"
#include "sw420_vibration_sensor.hpp"
#include "sw520d_tilt_sensor.hpp"
#include <iostream>

void controller() 
{
  wiringPiSetupGpio();
  pwmSetMode(PWM_MODE_MS);
  pwmSetClock(384);
  pwmSetRange(1000);

  SW420_Vibration_Sensor vibration_module(5);

  while (!vibration_module.isThereVibration()) {
    std::cout << "no vibration yet\n"; 
  }

  std::cout << "Vibration detected\n";
}

int main()
{
  controller(); 
  return 0;
}
