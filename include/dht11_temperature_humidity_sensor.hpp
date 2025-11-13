#ifndef DHT11_TEMPERATURE_HUMIDITY_SENSOR
#define DHT11_TEMPERATURE_HUMIDITY_SENSOR

#include <wiringPi.h>
#include <chrono>
#include <thread>
#include <cstdint>
#include <iostream>

constexpr std::chrono::seconds two_seconds_k{2};
constexpr std::chrono::milliseconds eighteen_milliseconds_k{18};

class DHT11_Temperature_Humidity_Sensor
{
public:
  DHT11_Temperature_Humidity_Sensor(int pinNumber) 
    : pinNumber_(pinNumber) {}
  void readTemperatureAndHumidity();
private:
  int pinNumber_;

  void sendStartSignal();
};

#endif // DHT11_TEMPERATURE_HUMIDITY_SENSOR
