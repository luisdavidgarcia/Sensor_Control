#ifndef SG90_SERVO_MOTOR_HPP
#define SG90_SERVO_MOTOR_HPP

#include <wiringPi.h>
#include <chrono>
#include <thread>

constexpr std::chrono::milliseconds two_ms_k{2};

class SG90_Servo_Motor
{
public:
  SG90_Servo_Motor(int pinNumber) : pinNumber_(pinNumber)
  {
    pinMode(pinNumber_, PWM_MS_OUTPUT);
  }
  void SetAngle(int degrees);
private:
  int pinNumber_;
};

#endif // SG90_SERVO_MOTOR_HPP
