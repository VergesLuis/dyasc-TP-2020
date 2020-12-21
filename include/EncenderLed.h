#ifndef EncenderLed_h
#define EncenderLed_h

#include "Arduino.h"
#include <string.h>


class EncenderLed
{
  public: 
    EncenderLed();

    //String getHHTPRequest(const char* serverName);
    void ledCorrecto(int);
    
  private:
    const int GreenLed = 23;
    const int YellowLed = 22;
    const int RedLed = 21;
    //int wifi_status_pin;  
   
};

#endif /* EncenderLed_h */
