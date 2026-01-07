#ifndef button_hpp
#define button_hpp
#include "periph.hpp"


class Button : public Periph{
public:
    Button(int pin);
    ~Button();

    bool isPressed();

};

#endif