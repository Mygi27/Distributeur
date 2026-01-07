#ifndef lcd_hpp
#define lcd_hpp

#include "periph.hpp"
#include <Wire.h>
#include <rgb_lcd.h> 

class Lcd : public Periph {
private:
    rgb_lcd _lcd; // L'objet lcd "réel" est contenu dans notre classe

public:
    Lcd();
    ~Lcd();

    void begin();

    void afficher(String ligne1, String ligne2);

    void setColor(int r, int g, int b);

    void clear();
};

#endif