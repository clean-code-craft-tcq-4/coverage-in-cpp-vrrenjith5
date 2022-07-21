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

class Cooling {

  public:

    Cooling(){}
    ~Cooling(){}
    virtual int getLowerLimit() = 0;
    virtual int getUpperLimit() = 0;
    BreachType inferBreach(double value);
};

class PassiveCooling : public Cooling {

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

class HighActiveCooling : public Cooling {

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

class MediumActiveCooling : public Cooling {

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

class CommunicationChannel {

  public:

    CommunicationChannel(){}
    ~CommunicationChannel(){}
    virtual void sendMessage(BreachType breachType) = 0;
};

class SendToController : public CommunicationChannel {

  public:

    SendToController(){}
    ~SendToController(){}
    void sendMessage(BreachType breachType) override;
};

class SendToEmail : public CommunicationChannel {

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

    Cooling *coolingType;
    CommunicationChannel *alertTarget;

  public:

    BreachType checkAndAlert(Cooling* cooling, CommunicationChannel* communicationChannel, double temperatureInC);
};

#endif /* __BATTERY_HEALTH_H_ */
