#include <iostream>
#include "battery_health.h"

BreachType BatteryCoolingType :: inferBreach(double value) {
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

BreachType BatteryHealth :: checkAndAlert (BatteryCoolingType* coolingType, BatteryAlertTarget* alertTarget, double temperatureInCelsius) {
  this->batteryCoolingType = coolingType;
  this->batteryAlertTarget = alertTarget;
  BreachType breachType = batteryCoolingType->inferBreach(temperatureInCelsius);
  batteryAlertTarget->sendMessage(breachType);
  return breachType;
}

