#include "periph.hpp"
#include <stdio.h>
#include <string>

periph::periph(){
};

periph::periph(int N,char mod){
    if ((mod == 'INPUT') or (mod == 'INPUT')){
    pin = N;
    mode = mod;
    }
};

void periph::setup(){
    void setup(){
    pinMode(pin, mod);
    }
}

periph::~periph() {
}
