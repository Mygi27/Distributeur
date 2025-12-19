#ifndef PERIPH_hpp
#define PERIPH_hpp

class periph{
protected: 
  int pin;
  char mode; // in or out.
public:
    periph();
    periph(int N,char mode);
    ~periph();
};

#endif