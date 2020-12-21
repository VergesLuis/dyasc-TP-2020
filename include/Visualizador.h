#ifndef Test_Led_h
#define Test_Led_h 

#include "Arduino.h"
#include <string.h>
class Visualizador{      
    private:
            enum State {CORRECT, FALLED, CANCELLED};
    public:
            virtual void visualizar_state(State estado);
    
};
#endif
