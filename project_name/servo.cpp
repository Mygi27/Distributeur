#include "servo.hpp"
#include <Arduino.h>

// ATTENTION : On utilise bien ServoMoteur::
ServoMoteur::ServoMoteur(int pin) : Periph(pin, OUTPUT) {
    _angleFerme = 0;
    _angleOuvert = 180;
}

ServoMoteur::~ServoMoteur() {
    if (_servo.attached()) {
        _servo.detach();
    }
}

void ServoMoteur::begin() {
    _servo.attach(_pin);
    _servo.write(_angleFerme);
}


void ServoMoteur::distribuer(int tempsOuverture) {
    _servo.write(_angleOuvert);
    delay(tempsOuverture);
    _servo.write(_angleFerme);
    delay(500); 
}