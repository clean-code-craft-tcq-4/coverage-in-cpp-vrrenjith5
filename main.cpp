#include <iostream>
#include "battery_health.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"

PassiveCooling passiveCooling;
HighActiveCooling highActiveCooling;
MediumActiveCooling mediumActiveCooling;
SendToEmail sendToEmail;
SendToController sendToController;
BatteryHealth batteryHealth;

TEST_CASE("PassiveCooling normal, send via email") {
BreachType breachType = batteryHealth.checkAndAlert(&passiveCooling, &sendToEmail, 30);
REQUIRE(breachType == NORMAL);
}

TEST_CASE("PassiveCooling too low, send via email") {
BreachType breachType = batteryHealth.checkAndAlert(&passiveCooling, &sendToEmail, -1);
REQUIRE(breachType == TOO_LOW);
}

TEST_CASE("PassiveCooling too high, send via controller") {
BreachType breachType = batteryHealth.checkAndAlert(&passiveCooling, &sendToController, 36);
REQUIRE(breachType == TOO_HIGH);
}

TEST_CASE("HighActiveCooling normal, send via email") {
BreachType breachType = batteryHealth.checkAndAlert(&highActiveCooling, &sendToController, 45);
REQUIRE(breachType == NORMAL);
}

TEST_CASE("HighActiveCooling too low, send via email") {
BreachType breachType = batteryHealth.checkAndAlert(&highActiveCooling, &sendToController, -1);
REQUIRE(breachType == TOO_LOW);
}

TEST_CASE("HighActiveCooling too high, send via controller") {
BreachType breachType = batteryHealth.checkAndAlert(&highActiveCooling, &sendToEmail, 46);
REQUIRE(breachType == TOO_HIGH);
}

TEST_CASE("MediumActiveCooling normal, send via email") {
BreachType breachType = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToEmail, 39);
REQUIRE(breachType == NORMAL);
}

TEST_CASE("MediumActiveCooling too low, send via email") {
BreachType breachType = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToController, -1);
REQUIRE(breachType == TOO_LOW);
}

TEST_CASE("MediumActiveCooling too high, send via controller") {
BreachType breachType = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToEmail, 41);
REQUIRE(breachType == TOO_HIGH);
}
