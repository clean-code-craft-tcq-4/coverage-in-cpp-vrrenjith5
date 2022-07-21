#ifndef __EMAIL_H_
#define __EMAIL_H_

typedef struct {
  std::string eMailId;
  std::string eMailSubjectLine;
  std::string eMailMessage;
}EmailParameters;

class Email{

  private:

	bool isEmailIdValid(const std::string& eMailId);
	EmailParameters emailParameters;

  public:

    Email(){}
    ~Email(){}
    void configureEmail(EmailParameters configureEmailParameters);
    bool sendEmail();
};

#endif /*__EMAIL_H_ */
