#include <iostream>

#include "battery_health.h"

void SendToController :: sendMessage(BreachType breachType) {
   Controller controller;
   controller.displyMessage(breachType);
}

void SendToEmail :: constructMessage(BreachType breachType) {
   batteryHealthEmailParameters.eMailId = "vrrenjith5@gmail.com";
   batteryHealthEmailParameters.eMailSubjectLine = "battery temperature monitor";
   batteryHealthEmailParameters.eMailMessage = TEMPERATURE_ALERT + batteryBreach[breachType];
}

void SendToEmail :: sendMessage(BreachType breachType) {
   constructMessage(breachType);
   batteryHealthEmail.configureEmail(batteryHealthEmailParameters);
   batteryHealthEmail.sendEmail();
}

BreachType Cooling :: inferBreach(double value) {
  if(value < getLowerLimit()) {
    return TOO_LOW;
  }
  if(value > getUpperLimit()) {
    return TOO_HIGH;
  }
  return NORMAL;
}

int PassiveCooling :: getLowerLimit() {
  return lowerLimit;
}

int PassiveCooling :: getUpperLimit() {
  return upperLimit;
}

int HighActiveCooling :: getLowerLimit() {
  return lowerLimit;
}

int HighActiveCooling :: getUpperLimit() {
  return upperLimit;
}

int MediumActiveCooling :: getLowerLimit() {
  return lowerLimit;
}

int MediumActiveCooling :: getUpperLimit() {
  return upperLimit;
}

void BatteryHealth :: checkAndAlert (Cooling* cooling, CommunicationChannel* communicationChannel, double temperatureInC) {
  this->coolingType = cooling;
  BreachType breachType = coolingType->inferBreach(temperatureInC);
  this->alertTarget = communicationChannel;
  alertTarget->sendMessage(breachType);
}




















/*class CoolingLimit
{
    public:
        virtual void SetLimit() const = 0;
        virtual void GetUpperLimit() const = 0;
        virtual void GetLowerLimit() const = 0;
};

class PassiveCooling: public CoolingLimit
{
    public:
        ConstructMessage

        virtual void SetLimit() const {
            controller_obj = Controller()
            controller_obj.disply_message(breach type)
            cout << "Merge sort()\n";
        }
};
class HighActiveCooling: public CoolingLimit
{
    public:
        ConstructMessage

        virtual void SetLimit() const {
            controller_obj = Controller()
            controller_obj.disply_message(breach type)
            cout << "Merge sort()\n";
        }
};

class MediumActiveCooling: public CoolingLimit {
    public:
        virtual void SetLimit() const {
            email_obj = Email()
            message =
            email_obj.configureEmail
            email_obj.send_message(message)
            cout << "Quick sort()\n";
        }
};*/
