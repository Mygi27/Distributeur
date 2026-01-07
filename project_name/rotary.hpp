#ifndef rotary_hpp
#define rotary_hpp

#include "periph.hpp"

class RotarySensor : public Periph {
private:
    int _nbChoix;
    int _lastSelection;

public:
    RotarySensor(int pin, int nbChoix);
    ~RotarySensor();
    int readSelection();
};

#endif