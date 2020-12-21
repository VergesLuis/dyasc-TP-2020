#ifndef CI_controller_h
#define CI_controller_h

#include "Arduino.h"
#include <string.h>
#include <EncenderLed.h>

class CI_controller
{
  public: 
    CI_controller();

    String getHHTPRequest(const char* serverName);
    void showAnswer(String answ);
    
  private:
    //int wifi_status_pin;  
   
};

#endif /* wifi_adapter_h */
