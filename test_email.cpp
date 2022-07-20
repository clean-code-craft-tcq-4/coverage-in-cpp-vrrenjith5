#include <iostream>
#include <assert.h>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "email.h"

using namespace std;

TEST_CASE("when mail id is valid sendEmail will be success") {
  Email email;
  EmailParameters emailParameters;
  emailParameters.eMailId = "vrrenjith5@gmail.com";
  emailParameters.eMailSubjectLine = "battery temperature monitor";
  emailParameters.eMailMessage = "temperature is too low";
  email.configureEmail(emailParameters);
  REQUIRE(email.sendEmail() == true);
}

TEST_CASE("when mail id is invalid(without @ symbol) sendEmail will be fail") {
  Email email;
  EmailParameters emailParameters;
  emailParameters.eMailId = "vrrenjith5gmail.com";
  emailParameters.eMailSubjectLine = "battery temperature monitor";
  emailParameters.eMailMessage = "temperature is too low";
  email.configureEmail(emailParameters);
  REQUIRE(email.sendEmail() == false);
}

TEST_CASE("when mail id is invalid(without . symbol) sendEmail will be fail") {
  Email email;
  EmailParameters emailParameters;
  emailParameters.eMailId = "vrrenjith5@gmailcom";
  emailParameters.eMailSubjectLine = "battery temperature monitor";
  emailParameters.eMailMessage = "temperature is too low";
  email.configureEmail(emailParameters);
  REQUIRE(email.sendEmail() == false);
}

TEST_CASE("when mail id is invalid(without @, . symbol) sendEmail will be fail") {
  Email email;
  EmailParameters emailParameters;
  emailParameters.eMailId = "vrrenjith5gmailcom";
  emailParameters.eMailSubjectLine = "battery temperature monitor";
  emailParameters.eMailMessage = "temperature is too low";
  email.configureEmail(emailParameters);
  REQUIRE(email.sendEmail() == false);
}

