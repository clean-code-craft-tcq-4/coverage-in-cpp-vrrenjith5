#include <iostream>
#include "controller.h"

void Controller :: displyMessage(int message){
  std::cout << std::hex << HEADER <<" "<< std::hex << message <<std::endl;
}
