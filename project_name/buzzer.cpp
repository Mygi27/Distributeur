#include "buzzer.hpp"
#include <arduino.h>

Buzzer::Buzzer(int pin) : Periph(pin, OUTPUT) {
}

Buzzer::~Buzzer() {
}

void Buzzer::beep(int duration) {
    digitalWrite(_pin, HIGH);
    delay(duration);
    digitalWrite(_pin, LOW);
}

void Buzzer::stop() {
    digitalWrite(_pin, LOW);
}