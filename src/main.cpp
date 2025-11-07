#include <wiringPi.h>

#include "hcsr04_ultrasonic_sensor.hpp"
#include "raindrop_sensor.hpp"
#include "sg90_servo_motor.hpp"
#include "sw420_vibration_sensor.hpp"
#include "sw520d_tilt_sensor.hpp"
#include <iostream>

constexpr int tiltSensorPin{4};               // 23
constexpr int vibrationSensorPin{5};          // 24
constexpr int raindropSensorPin{6};           // 25
constexpr int humiditySensorPin{27};          // 16
constexpr int backServoPin{26};               // 12
constexpr int frontServoPin{23};              // 13
constexpr int backUltrasonicTriggerPin{0};    // 17
constexpr int backUltrasonicEchoPin{2};       // 27
constexpr int frontUltrasonicTriggerPin{21};  // 5
constexpr int frontUltrasonicEchoPin{22};     // 6

void controller() 
{
  wiringPiSetupGpio();
  pwmSetMode(PWM_MODE_MS);
  pwmSetClock(384);
  pwmSetRange(1000);

  SW420_Vibration_Sensor vibration_module(vibrationSensorPin);
  SW520D_Tilt_Sensor tilt_module(tiltSensorPin);
  Raindrop_Sensor raindrop_module(raindropSensorPin);
  SG90_Servo_Motor back_servo{backServoPin};
  SG90_Servo_Motor front_servo{frontServoPin};
  HCSR04_Ultrasonic_Sensor backUltrasonic(
    backUltrasonicTriggerPin,
    backUltrasonicEchoPin);
  HCSR04_Ultrasonic_Sensor frontUltrasonic(
    frontUltrasonicTriggerPin,
    frontUltrasonicEchoPin);

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
