#ifndef lcd_hpp
#define lcd_hpp

#include "periph.hpp"
#include <Wire.h>
#include <rgb_lcd.h> 

class Lcd : public Periph {
private:
    rgb_lcd _lcd; // classe rgb_lcd defini dans rgb_lcd.h 

public:
    Lcd();
    ~Lcd();

    void begin();

    void afficher(String ligne1, String ligne2);

    void clear();
};

#endif