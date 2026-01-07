#include "lcd.hpp"
#include <arduino.h>


Lcd::Lcd() : Periph(-1, 0) {
}

Lcd::~Lcd() {
}

void Lcd::begin() {

    _lcd.begin(16, 2);
    _lcd.setRGB(255, 255, 255);
}

void Lcd::afficher(String ligne1, String ligne2) {
    _lcd.clear();

    _lcd.setCursor(0, 0);
    _lcd.print(ligne1);
    
    _lcd.setCursor(0, 1);
    _lcd.print(ligne2);
}


void Lcd::clear() {
    _lcd.clear();
}