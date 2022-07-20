#include <iostream>
//#include "email.h"
//#include "controller.h"
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

  return 0;
}
