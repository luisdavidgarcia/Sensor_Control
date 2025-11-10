#ifndef SG90_SERVO_MOTOR_HPP
#define SG90_SERVO_MOTOR_HPP

#include <wiringPi.h>
#include <chrono>
#include <thread>

constexpr int maxAngle{180};
constexpr int minPWMValue{100};

class SG90_Servo_Motor
{
public:
  SG90_Servo_Motor(int pinNumber) : pinNumber_(pinNumber)
  {
    pinMode(pinNumber_, PWM_MS_OUTPUT);
  }
  void setAngle(int angleDegrees);
private:
  int pinNumber_;
};

#endif // SG90_SERVO_MOTOR_HPP
