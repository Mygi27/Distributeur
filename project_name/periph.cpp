#include "periph.hpp"
#include <stdio.h>
#include <string>
#include <arduino.h>
periph::periph(){
}

periph::periph(int N,int mod){ 
    if (mod == INPUT){
    pin = N;
    mode = INPUT;
    }else {
    pin = N;
    mode = OUTPUT;
    }
    
}

void periph::setup(){
    void setup(){
    pinMode(pin, mode);
    }
}

periph::~periph() {
}
