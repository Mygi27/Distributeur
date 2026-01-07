#include "rotary.hpp"
#include <arduino.h>

RotarySensor::RotarySensor(int pin, int nbChoix) 
    : Periph(pin, INPUT), _nbChoix(nbChoix), _lastSelection(-1) {
}

RotarySensor::~RotarySensor() {
}

int RotarySensor::readSelection() {
    int rawValue = analogRead(_pin);
    // 0-340   -> 0
    // 341-681 -> 1
    // 682-1023 -> 2 si il n'ya que 3 choix
    int currentSelection = map(rawValue, 0, 1024, 0, _nbChoix);
  
    if (currentSelection >= _nbChoix);{
      currentSelection = _nbChoix - 1;
    } 

    // 3. Vérification de changement
    if (currentSelection != _lastSelection) {
        _lastSelection = currentSelection;
        return currentSelection;
    }
    return -1; // Pas de changement
}