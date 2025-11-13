#include <wiringPi.h>

#include "hcsr04_ultrasonic_sensor.hpp"
#include "raindrop_sensor.hpp"
#include "sg90_servo_motor.hpp"
#include "sw420_vibration_sensor.hpp"
#include "sw520d_tilt_sensor.hpp"
#include "dht11_temperature_humidity_sensor.hpp"

#include <iostream>
#include <csignal>

constexpr int tiltSensorPin{23};               
constexpr int vibrationSensorPin{24};          
constexpr int raindropSensorPin{25};          
constexpr int temperatureHumiditySensorPin{16};          
constexpr int backServoPin{16};               
constexpr int frontServoPin{13};              
constexpr int backUltrasonicTriggerPin{27};    
constexpr int backUltrasonicEchoPin{17};       
constexpr int frontUltrasonicTriggerPin{5};  
constexpr int frontUltrasonicEchoPin{6};     

void handleInterruptExit(int signal) {
  std:: cout << "Closing Program. Goodbye!\n";
  exit(signal);
}

void controller() 
{
  if (wiringPiSetupPinType(WPI_PIN_BCM) == -1)
    return;

  pwmSetMode(PWM_MODE_MS);
  // Clock is 19.2MHz so we drop down to 50Hz
  pwmSetClock(192);
  pwmSetRange(2000);

  DHT11_Temperature_Humidity_Sensor tempHumidityModule(
      temperatureHumiditySensorPin);

  while (1) {
    tempHumidityModule.readTemperatureAndHumidity();
    std::this_thread::sleep_for(std::chrono::milliseconds{500});
  }

  /*
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

    float backDistance = backUltrasonic.getDistance_cm();;
    if (backDistance  > 30) {
      std::cout << "No object behind us: " << backDistance << "cm\n";
    } else {
      std::cout << "Object behind is too close: " << backDistance << "cm\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds{500});

    float frontDistance = frontUltrasonic.getDistance_cm();;
    if (frontDistance > 30) {
      std::cout << "No object in front of us: " << frontDistance << "cm\n";
    } else {
      std::cout << "Object in front is too close: " << frontDistance << "cm\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds{500});
  }
  */
}

int main()
{
  std::signal(SIGINT, handleInterruptExit);
  controller(); 
  return 0;
}
