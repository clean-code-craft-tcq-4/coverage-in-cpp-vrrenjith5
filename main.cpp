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
bool isAlertMessageSend;

TEST_CASE("PassiveCooling breach, send via email") {
isAlertMessageSend = batteryHealth.checkAndAlert(&passiveCooling, &sendToEmail, 30);
REQUIRE(isAlertMessageSend == false);
isAlertMessageSend = batteryHealth.checkAndAlert(&passiveCooling, &sendToEmail, -1);
REQUIRE(isAlertMessageSend == true);
isAlertMessageSend = batteryHealth.checkAndAlert(&passiveCooling, &sendToEmail, 36);
REQUIRE(isAlertMessageSend == true);
}

TEST_CASE("PassiveCooling breach, send via controller") {
isAlertMessageSend = batteryHealth.checkAndAlert(&passiveCooling, &sendToController, 30);
REQUIRE(isAlertMessageSend == false);
isAlertMessageSend = batteryHealth.checkAndAlert(&passiveCooling, &sendToController, -1);
REQUIRE(isAlertMessageSend == true);
isAlertMessageSend = batteryHealth.checkAndAlert(&passiveCooling, &sendToController, 36);
REQUIRE(isAlertMessageSend == true);
}


TEST_CASE("HighActiveCooling breach, send via email") {
isAlertMessageSend = batteryHealth.checkAndAlert(&highActiveCooling, &sendToEmail, 45);
REQUIRE(isAlertMessageSend == false);
isAlertMessageSend = batteryHealth.checkAndAlert(&highActiveCooling, &sendToEmail, -1);
REQUIRE(isAlertMessageSend == true);
isAlertMessageSend = batteryHealth.checkAndAlert(&highActiveCooling, &sendToEmail, 46);
REQUIRE(isAlertMessageSend == true);
}

TEST_CASE("HighActiveCooling breach, send via controller") {
isAlertMessageSend = batteryHealth.checkAndAlert(&highActiveCooling, &sendToController, 45);
REQUIRE(isAlertMessageSend == false);
isAlertMessageSend = batteryHealth.checkAndAlert(&highActiveCooling, &sendToController, -1);
REQUIRE(isAlertMessageSend == true);
isAlertMessageSend = batteryHealth.checkAndAlert(&highActiveCooling, &sendToController, 46);
REQUIRE(isAlertMessageSend == true);
}

TEST_CASE("MediumActiveCooling breach, send via email") {
isAlertMessageSend = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToEmail, 39);
REQUIRE(isAlertMessageSend == false);
isAlertMessageSend = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToEmail, -1);
REQUIRE(isAlertMessageSend == true);
isAlertMessageSend = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToEmail, 41);
REQUIRE(isAlertMessageSend == true);
}

TEST_CASE("MediumActiveCooling breach, send via controller") {
isAlertMessageSend = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToController, 39);
REQUIRE(isAlertMessageSend == false);
isAlertMessageSend = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToController, -1);
REQUIRE(isAlertMessageSend == true);
isAlertMessageSend = batteryHealth.checkAndAlert(&mediumActiveCooling, &sendToController, 41);
REQUIRE(isAlertMessageSend == true);
}

