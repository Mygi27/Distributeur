#include "periph.hpp"
#include <arduino.h>

Periph::Periph(int pin,int mode) : _pin(pin), _mode(mode){ 
}
Periph::~Periph() {
}

void Periph::begin(){
  if (_pin >= 0) {
        pinMode(_pin, _mode);
    }
}


