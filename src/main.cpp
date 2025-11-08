#include <wiringPi.h>

#include "hcsr04_ultrasonic_sensor.hpp"
#include "raindrop_sensor.hpp"
#include "sg90_servo_motor.hpp"
#include "sw420_vibration_sensor.hpp"
#include "sw520d_tilt_sensor.hpp"
#include <iostream>

constexpr int tiltSensorPin{23};               // 23
constexpr int vibrationSensorPin{24};          // 24
constexpr int raindropSensorPin{25};           // 25
constexpr int humiditySensorPin{16};          // 16
constexpr int backServoPin{16};               // 12
constexpr int frontServoPin{13};              // 13
constexpr int backUltrasonicTriggerPin{17};    // 17
constexpr int backUltrasonicEchoPin{27};       // 27
constexpr int frontUltrasonicTriggerPin{5};  // 5
constexpr int frontUltrasonicEchoPin{6};     // 6

void controller() 
{
  if (wiringPiSetupPinType(WPI_PIN_BCM) == -1)
    return;

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

  //while (!vibration_module.isThereVibration()) {
  //  std::cout << "no vibration yet\n"; 
  //}

  while (1) { 
    if (!tilt_module.isThereTilt()) {
      std::cout << "no tilt yet\n"; 
    } else {
      std::cout << "tilt\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds{500});
  }
  //std::cout << "getting distance\n";
  //std::cout << backUltrasonic.getDistance_mm() << "\n";

}

int main()
{
  controller(); 
  return 0;
}
