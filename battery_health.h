#ifndef __BATTERY_HEALTH_H_
#define __BATTERY_HEALTH_H_

#include <vector>
#include "email.h"
#include "controller.h"

const std::string TEMPERATURE_ALERT =  "Hi, the temperature is ";
const std::vector<std::string> batteryBreach = {"normal", "too low", "too high"};

typedef enum {
  NORMAL = 0,
  TOO_LOW,
  TOO_HIGH
} BreachType;

class BatteryCoolingType {

  public:

    BatteryCoolingType(){}
    ~BatteryCoolingType(){}
    virtual int getLowerLimit() = 0;
    virtual int getUpperLimit() = 0;
    BreachType inferBreach(double value);
};

class PassiveCooling : public BatteryCoolingType {

  protected:

    int lowerLimit;
    int upperLimit;

  public:

    PassiveCooling(){
      lowerLimit = 0;
      upperLimit = 35;
    }
    ~PassiveCooling(){}
    int getLowerLimit()override;
    int getUpperLimit()override;
};

class HighActiveCooling : public BatteryCoolingType {

  protected:

    int lowerLimit;
    int upperLimit;

  public:

    HighActiveCooling(){
      lowerLimit = 0;
      upperLimit = 45;
    }
    ~HighActiveCooling(){}
    int getLowerLimit()override;
    int getUpperLimit()override;
};

class MediumActiveCooling : public BatteryCoolingType {

  protected:

    int lowerLimit;
    int upperLimit;

  public:

    MediumActiveCooling(){
      lowerLimit = 0;
      upperLimit = 40;
    }
    ~MediumActiveCooling(){}
    int getLowerLimit()override;
    int getUpperLimit()override;
};

class BatteryAlertTarget {

  public:

    BatteryAlertTarget(){}
    ~BatteryAlertTarget(){}
    virtual void sendMessage(BreachType breachType) = 0;
};

class SendToController : public BatteryAlertTarget {

  public:

    SendToController(){}
    ~SendToController(){}
    void sendMessage(BreachType breachType) override;
};

class SendToEmail : public BatteryAlertTarget {

  private:

    Email batteryHealthEmail;
    EmailParameters batteryHealthEmailParameters;
    void constructMessage(BreachType breachType);

  public:

    SendToEmail(){}
    ~SendToEmail(){}
    void sendMessage(BreachType breachType)override;
};

class BatteryHealth {

  private:

    BatteryCoolingType *batteryCoolingType;
    BatteryAlertTarget *batteryAlertTarget;

  public:

    BreachType checkAndAlert(BatteryCoolingType* coolingType, BatteryAlertTarget* alertTarget, double temperatureInC);
};

#endif /* __BATTERY_HEALTH_H_ */
