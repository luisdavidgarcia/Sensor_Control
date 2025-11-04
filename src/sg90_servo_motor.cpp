#include "sg90_servo_motor.hpp"

static const std::chrono::milliseconds two_ms_k std::chrono::milliseconds(2);

void SG90_Servo_Motor::SetAngle(int degrees)
{
  pwmWrite(pinNumber_, degrees); 
  std::this_thread::sleep_for(two_ms_k);
}
