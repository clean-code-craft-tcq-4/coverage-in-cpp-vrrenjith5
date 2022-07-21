#include <iostream>
#include "battery_health.h"

using namespace std;

int main()
{
   PassiveCooling passiveCooling;
   HighActiveCooling highActiveCooling;
   MediumActiveCooling mediumActiveCooling;

   SendToEmail sendToEmail;
   SendToController sendToController;

   BatteryHealth batteryHealth;

   batteryHealth.checkAndAlert(&passiveCooling, &sendToController, 30);
   batteryHealth.checkAndAlert(&passiveCooling, &sendToEmail, 36);

  return 0;
}
