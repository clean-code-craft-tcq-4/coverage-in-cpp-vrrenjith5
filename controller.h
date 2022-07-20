#ifndef __CONTROLLER_H_
#define __CONTROLLER_H_

class Controller{
  private:
    const unsigned short HEADER = 0xfeed;
  public:
    Controller(){}
    ~Controller(){}
    void displyMessage(int message);
};

#endif /* __CONTROLLER_H_ */
