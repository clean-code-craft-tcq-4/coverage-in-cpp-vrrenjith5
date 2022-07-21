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
BreachType breachType;

TEST_CASE("PassiveCooling breach, send via email") {
breachType = batteryHealth.checkAndAlert(&passiveCooling, &sendToEmail, 30);
REQUIRE(breachType == NORMAL);
breachType = batteryHealth.checkAndAlert(&passiveCooling, &sendToEmail, -1);
REQUIRE(breachType == TOO_LOW);
breachType = batteryHealth.checkAndAlert(&passiveCooling, &sendToEmail, 36);
REQUIRE(breachType == TOO_HIGH);
}

TEST_CASE("PassiveCooling breach, send via controller") {
breachType = batteryHealth.checkAndAlert(&passiveCooling, &sendToController, 30);
REQUIRE(breachType == NORMAL);
breachType = batteryHealth.checkAndAlert(&passiveCooling, &sendToController, -1);
REQUIRE(breachType == TOO_LOW);
breachType = batteryHealth.checkAndAlert(&passiveCooling, &sendToController, 36);
REQUIRE(breachType == TOO_HIGH);
}


TEST_CASE("HighActiveCooling breach, send via email") {
breachType = batteryHealth.checkAndAlert(&highActiveCooling, &sendToEmail, 45);
REQUIRE(breachType == NORMAL);
breachType = batteryHealth.checkAndAlert(&highActiveCooling, &sendToEmail, -1);
REQUIRE(breachType == TOO_LOW);
breachType = batteryHealth.checkAndAlert(&highActiveCooling, &sendToEmail, 46);
REQUIRE(breachType == TOO_HIGH);
}

TEST_CASE("HighActiveCooling breach, send via controller") {
breachType = batteryHealth.checkAndAlert(&highActiveCooling, &sendToController, 45);
REQUIRE(breachType == NORMAL);
breachType = batteryHealth.checkAndAlert(&highActiveCooling, &sendToController, -1);
REQUIRE(breachType == TOO_LOW);
breachType = batteryHealth.checkAndAlert(&highActiveCooling, &sendToController, 46);
REQUIRE(breachType == TOO_HIGH);
}

TEST_CASE("MediumActiveCooling breach, send via email") {
breachType = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToEmail, 39);
REQUIRE(breachType == NORMAL);
breachType = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToEmail, -1);
REQUIRE(breachType == TOO_LOW);
breachType = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToEmail, 41);
REQUIRE(breachType == TOO_HIGH);
}

TEST_CASE("MediumActiveCooling breach, send via controller") {
breachType = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToController, 39);
REQUIRE(breachType == NORMAL);
breachType = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToController, -1);
REQUIRE(breachType == TOO_LOW);
breachType = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToController, 41);
REQUIRE(breachType == TOO_HIGH);
}

