#include "button.hpp"
#include <stdio.h>

button::button(){
};


button::~button() {
}

bool button::isPressed(){
    return status;
}