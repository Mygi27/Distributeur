#ifndef PERIPH_hpp
#define PERIPH_hpp
#include <string>
//#include <arduino.h>

class Periph{
protected: 
  int _pin;
  int _mode; // INPUT or OUTPUT
public:
    Periph(int pin,int mode);
    ~Periph();
    void begin();
};

#endif