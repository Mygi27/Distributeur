#ifndef PERIPH_hpp
#define PERIPH_hpp
#include <string>
using namespace std;


class periph{
protected: 
  int pin;
  string mode;
public:
    periph();
    periph(int N,string mod);
    ~periph();
    void setup();
};

#endif