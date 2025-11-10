#include "sg90_servo_motor.hpp"

void SG90_Servo_Motor::setAngle(int angleDegrees)
{
  int pwmValue = minPWMValue * angleDegrees / maxAngle + minPWMValue;
  pwmWrite(pinNumber_, pwmValue); 
  std::this_thread::sleep_for(std::chrono::seconds{1});
}
