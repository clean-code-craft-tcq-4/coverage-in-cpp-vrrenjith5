#include <iostream>
#include <algorithm>
#include "email.h"

bool Email :: isEmailIdValid(const std::string& eMailId){
  auto characterAt = find(eMailId.begin(), eMailId.end(), '@');
  auto characterDot  = find(characterAt, eMailId.end(), '.');
  return (characterAt != eMailId.end()) && (characterDot != eMailId.end());
}

void Email :: configureEmail(EmailParameters configureEmailParameters) {
  emailParameters.eMailId = configureEmailParameters.eMailId;
  emailParameters.eMailSubjectLine = configureEmailParameters.eMailSubjectLine;
  emailParameters.eMailMessage = configureEmailParameters.eMailMessage;
}

bool Email :: sendEmail(){
  bool isSendEmailSuccess = false;
  if(isEmailIdValid(emailParameters.eMailId)) {
    std::cout<<"To: "<<emailParameters.eMailId<<std::endl;
    std::cout<<"Subject: "<<emailParameters.eMailSubjectLine<<std::endl;
    std::cout<<"Mail Body: "<<emailParameters.eMailMessage<<std::endl;
    isSendEmailSuccess = true;
  }
  return isSendEmailSuccess;
}
