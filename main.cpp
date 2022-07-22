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
bool isAlertRequired;

TEST_CASE("PassiveCooling breach, send via email") {
isAlertRequired = batteryHealth.checkAndAlert(&passiveCooling, &sendToEmail, 30);
REQUIRE(isAlertRequired == false);
isAlertRequired = batteryHealth.checkAndAlert(&passiveCooling, &sendToEmail, -1);
REQUIRE(isAlertRequired == true);
isAlertRequired = batteryHealth.checkAndAlert(&passiveCooling, &sendToEmail, 36);
REQUIRE(isAlertRequired == true);
}

TEST_CASE("PassiveCooling breach, send via controller") {
isAlertRequired = batteryHealth.checkAndAlert(&passiveCooling, &sendToController, 30);
REQUIRE(isAlertRequired == false);
isAlertRequired = batteryHealth.checkAndAlert(&passiveCooling, &sendToController, -1);
REQUIRE(isAlertRequired == true);
isAlertRequired = batteryHealth.checkAndAlert(&passiveCooling, &sendToController, 36);
REQUIRE(isAlertRequired == true);
}


TEST_CASE("HighActiveCooling breach, send via email") {
isAlertRequired = batteryHealth.checkAndAlert(&highActiveCooling, &sendToEmail, 45);
REQUIRE(isAlertRequired == false);
isAlertRequired = batteryHealth.checkAndAlert(&highActiveCooling, &sendToEmail, -1);
REQUIRE(isAlertRequired == true);
isAlertRequired = batteryHealth.checkAndAlert(&highActiveCooling, &sendToEmail, 46);
REQUIRE(isAlertRequired == true);
}

TEST_CASE("HighActiveCooling breach, send via controller") {
isAlertRequired = batteryHealth.checkAndAlert(&highActiveCooling, &sendToController, 45);
REQUIRE(isAlertRequired == false);
isAlertRequired = batteryHealth.checkAndAlert(&highActiveCooling, &sendToController, -1);
REQUIRE(isAlertRequired == true);
isAlertRequired = batteryHealth.checkAndAlert(&highActiveCooling, &sendToController, 46);
REQUIRE(isAlertRequired == true);
}

TEST_CASE("MediumActiveCooling breach, send via email") {
isAlertRequired = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToEmail, 39);
REQUIRE(isAlertRequired == false);
isAlertRequired = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToEmail, -1);
REQUIRE(isAlertRequired == true);
isAlertRequired = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToEmail, 41);
REQUIRE(isAlertRequired == true);
}

TEST_CASE("MediumActiveCooling breach, send via controller") {
isAlertRequired = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToController, 39);
REQUIRE(isAlertRequired == false);
isAlertRequired = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToController, -1);
REQUIRE(isAlertRequired == true);
isAlertRequired = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToController, 41);
REQUIRE(isAlertRequired == true);
}

