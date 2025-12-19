#include "periph.hpp"
#include <stdio.h>
#include <string>
//#include <arduino.h>

#define INPUT 0x00
#define ONPUT 0x01

periph::periph(){
}

periph::periph(int N,int mod){ 
    if (mod == INPUT){
    pin = N;
    mode = INPUT;
    printf("construction periph %d INPUT\n", N);
    }else {
    pin = N;
    mode = OUTPUT;
    printf("construction periph %d OUTPUT\n", N);
    }
    
}

void periph::setup(){
    void setup(){
    pinMode(pin, mode);
    }
}

periph::~periph() {
}
