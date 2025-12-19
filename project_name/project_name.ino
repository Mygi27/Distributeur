#include <rgb_lcd.h>

#include "button.hpp"
#include "buzzer.hpp"
#include "rotary.hpp"
#include "servo.hpp"
#include <stdio.h>
#include <Wire.h>

rgb_lcd lcd;

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("choisissez votre boisson !");
}

void loop() {
    // Turn off the display:
    lcd.noDisplay();
    delay(800);
    // Turn on the display:
    lcd.display();
    delay(800);
}