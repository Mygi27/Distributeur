#ifndef button_hpp
#define button_hpp

#include <arduino.h>

class button : public periph{
protected: 
  int buttonpin;
  bool status = 0;
public:
    button();
    ~button();
    bool isPressed();
};

#endif