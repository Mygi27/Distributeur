#include "button.hpp"
#include <arduino.h>

Button::Button(int pin) : Periph(pin, INPUT_PULLUP) {
}

Button::~Button() {
}

bool Button::isPressed() {
    return (digitalRead(_pin) == LOW);
}