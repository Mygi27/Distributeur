#ifndef PERIPH_hpp
#define PERIPH_hpp
#include <string>
//#include <arduino.h>
using namespace std;

class periph{
protected: 
  int pin;
  int mode; // INPUT or OUTPUT
public:
    periph();
    periph(int N,string mod);
    ~periph();
    void setup();
};

#endif