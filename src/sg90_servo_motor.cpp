#include "sg90_servo_motor.hpp"

void SG90_Servo_Motor::SetAngle(int degrees)
{
  pwmWrite(pinNumber_, degrees); 
  std::this_thread::sleep_for(two_ms_k);
}
