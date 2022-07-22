#include <iostream>
#include "battery_health.h"

BreachType BatteryCoolingType :: inferBreach(double value) {
  BreachType breachType = NORMAL;
  if(value < getLowerLimit()) {
    breachType = TOO_LOW;
  }
  if(value > getUpperLimit()) {
    breachType = TOO_HIGH;
  }
  return breachType;
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

bool BatteryHealth :: checkAndAlert (BatteryCoolingType* coolingType, BatteryAlertTarget* alertTarget, double temperatureInCelsius) {
  bool isAlertMessageSend = false;
  this->batteryCoolingType = coolingType;
  this->batteryAlertTarget = alertTarget;
  BreachType breachType = batteryCoolingType->inferBreach(temperatureInCelsius);

  if (breachType != NORMAL) {
    batteryAlertTarget->sendMessage(breachType);
    isAlertMessageSend = true;
  }
  return isAlertMessageSend;
}

