#include "Arduino.h"
#include <string.h>
#include <EncenderLed.h>


EncenderLed::EncenderLed(){
 

}

void EncenderLed::ledCorrecto(int led) {
    digitalWrite(RedLed, LOW);
    digitalWrite(GreenLed, LOW);
    digitalWrite(YellowLed, LOW);
    digitalWrite(led, HIGH);

};

