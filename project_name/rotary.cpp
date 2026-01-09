#include "rotary.hpp"
#include <arduino.h>

RotarySensor::RotarySensor(int pin, int nbChoix) : Periph(pin, INPUT), _nbChoix(nbChoix), _lastSelection(-1) {
}

RotarySensor::~RotarySensor() {
}

int RotarySensor::getCurrentState() {
    int rawValue = analogRead(_pin);

    if (rawValue > 1015) rawValue = 1023; 
    if (rawValue < 10) rawValue = 0;      
    int selection = map(rawValue, 1024, 0 , 0, _nbChoix);
    selection = constrain(selection, 0, _nbChoix - 1); //if (selection > _nbChoix-1) throw 1; // exception si une boisson hors index est sélectionnée.
    return selection;
}

int RotarySensor::readSelection() {
    int currentSelection = getCurrentState();

    if (currentSelection != _lastSelection) {
        _lastSelection = currentSelection;
        return currentSelection;
    }

    return -1;
}