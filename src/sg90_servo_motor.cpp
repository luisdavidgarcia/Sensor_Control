#include "sg90_servo_motor.hpp"

void SG90_Servo_Motor::SetAngle(int degrees)
{
  int pwmValue = minPWMValue * angle / maxAngle + minPWMValue;
  pwmWrite(pinNumber_, degrees); 
  std::this_thread::sleep_for(one_s_k);
}
