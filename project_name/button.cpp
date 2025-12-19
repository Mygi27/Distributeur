#include "button.hpp"
#include <stdio.h>
//#include <arduino.h>

#define INPUT 0x00
#define ONPUT 0x01

button::button(): periph(0,INPUT),buttonpin(0){
    printf("construction bouton pin %d\n",pin);
};


button::button(int pin): periph(pin,INPUT),buttonpin(pin){
    printf("construction bouton pin %d\n",pin);
};


button::~button() {
}

bool button::isPressed(){
    return digitalRead(buttonPin);
}