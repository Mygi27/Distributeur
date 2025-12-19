#ifndef PERIPH_hpp
#define PERIPH_hpp
#include <string>

class periph{
protected: 
  int pin;
  string mode; // in or out.
public:
    periph();
    periph(int N,string mode);
    ~periph();
    void setup();
};

#endif