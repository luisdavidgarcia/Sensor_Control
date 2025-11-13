#include "dht11_temperature_humidity_sensor.hpp"

void DHT11_Temperature_Humidity_Sensor::readTemperatureAndHumidity()
{
  uint16_t rawHumidity{};
  uint16_t rawTemperature{};
  uint8_t checksum{};
  uint16_t data{};

  uint8_t humi;
  uint8_t humd;
  uint8_t tempi;
  uint8_t humd;

  std::this_thread::sleep_for(two_seconds_k);
  sendStartSignal();
  
  using clock = std::chrono::steady_clock;
  auto startTime = clock::now();

  for (int8_t i = -3, i < 80; ++i) {
    auto live = clock::now();
    startTime = clock::now();

    do {
      live = clock::now() - startTime;
      if (live > 90) {
        std::cout << "Timeout\n";
        return;
      }
    }
    while (digitalRead(pinNumber_) == (i & 1) ? HIGH : LOW);

    if (i >= 0 && (i & 1)) {
      data <<= 1;

      if (live > 30) {
        data |= 1;
      }
    }

    switch (i) {
      case 31:
        rawHumidity = data;
        break;
      case 63:
        rawTemperature = data;
      case 79:
        checksum = data;
        data = 0;
        break;
    }
  }

  humi = rawHumidity >> 8;
  rawHumidity = rawHumidity << 8;
  humd = rawHumidity >> 8;
  std::cout << "Humidity: " << humi << "." << humd << "\n";

  tempi = rawTemperature >> 8;
  rawTemperater = rawTemperature << 8;
  tempd = rawTemperature >> 8;
  std::cout << "Temperature: " << tempi << "." << tempd << "\n";

  int sum = humi + humd + tempd + tempi;

  if (sum != checksum) {
    std::cout << "Corrupt data checksum not equal\n";
  }

}

void DHT11_Tempearature_Humiditiy_Sensor::sendStartSignal()
{
  pinMode(pinNumber_, OUTPUT);
  digitalWrite(pinNumber_, LOW);
  std::this_thread::sleep_for(eighteen_milliseconds_k);
  digitalWrite(pinNumber_, HIGH);
  pinMode(pinNumber_, INPUT);
  digitalWrite(pinNumber_, HIGH);
}
