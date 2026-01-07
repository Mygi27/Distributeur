#ifndef servo_hpp
#define servo_hpp

#include "periph.hpp"
#include <Servo.h>


class ServoMoteur : public Periph {
private:
    Servo _servo;
    int _angleFerme;
    int _angleOuvert;

public:
    ServoMoteur(int pin);
    ~ServoMoteur();

    void begin();
    void distribuer(int tempsOuverture);
};

#endif