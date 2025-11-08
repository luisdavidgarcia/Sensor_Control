# Sensor_Control

## WiringPi Install

Follow the `README` instructions on their repo, but this worked for me at least:

```sh
git clone https://github.com/WiringPi/WiringPi.git
cd WiringPi
./build debian
mv debian-template/wiringpi_3.16_arm64.deb .
sudo apt install ./wiringpi_3.16_arm64.deb
```
