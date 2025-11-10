#include <wiringPi.h>

#include "hcsr04_ultrasonic_sensor.hpp"
#include "raindrop_sensor.hpp"
#include "sg90_servo_motor.hpp"
#include "sw420_vibration_sensor.hpp"
#include "sw520d_tilt_sensor.hpp"

#include <iostream>
#include <csignal>

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

void handleInterruptExit(int signal) {
  std:: cout << "Closing Program. Goodbye!\n";
  exit(signal);
}

void controller() 
{
  if (wiringPiSetupPinType(WPI_PIN_BCM) == -1)
    return;

  pwmSetMode(PWM_MODE_MS);
  pwmSetClock(384);
  pwmSetRange(1000);

  SW420_Vibration_Sensor vibrationModule(vibrationSensorPin);
  SW520D_Tilt_Sensor tiltModule(tiltSensorPin);
  Raindrop_Sensor raindropModule(raindropSensorPin);

  SG90_Servo_Motor backServo{backServoPin};
  SG90_Servo_Motor frontServo{frontServoPin};

  HCSR04_Ultrasonic_Sensor backUltrasonic(
    backUltrasonicTriggerPin,
    backUltrasonicEchoPin);
  HCSR04_Ultrasonic_Sensor frontUltrasonic(
    frontUltrasonicTriggerPin,
    frontUltrasonicEchoPin);

  while (1) { 
    if (!tiltModule.isThereTilt()) {
      std::cout << "No tilt yet\n"; 
    } else {
      std::cout << "Tilt\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds{500});

    if (!vibrationModule.isThereVibration()) {
      std::cout << "No vibration yet\n";
    } else {
      std::cout << "Vibration\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds{500});

    if (raindropModule.isThereWater()) {
      std::cout << "No water yet\n";
    } else {
      std::cout << "Water!\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds{500});

    if (backUltrasonic.getDistance_mm() < 500) {
      std::cout << "No object behind us\n";
    } else {
      std::cout << "Object behind is too close\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds{500});

    if (frontUltrasonic.getDistance_mm() < 500) {
      std::cout << "No object in front of us\n";
    } else {
      std::cout << "Object in front is too close\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds{500});
  }
}

int main()
{
  std::signal(SIGINT, handleInterruptExit);
  controller(); 
  return 0;
}
