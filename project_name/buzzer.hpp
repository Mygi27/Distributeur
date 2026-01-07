#ifndef buzzer_hpp
#define buzzer_hpp
#include "periph.hpp"

class Buzzer : public Periph {
public:
    Buzzer(int pin);
    ~Buzzer();
    
    void beep(int duration);
    void stop();
};

#endif