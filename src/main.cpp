#include <wiringPi.h>

void controller() 
{
  wiringPiSetupGpio();
  pwmSetMode(PWM_MODE_MS);
  pwmSetClock(384);
  pwmSetRange(1000);
}

int main()
{
    return 0;
}
