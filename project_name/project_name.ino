#include "button.hpp"
#include "buzzer.hpp"
#include "rotary.hpp"
#include "lcd.hpp"
#include "servo.hpp"  // À adapter


Button btnValider(13);
Button paiement(14); 
Buzzer buzzer(12);
Lcd ecran;
RotarySensor sensor(A0, 6);
ServoMoteur monServo(15);

const char* boissons[] = {"1. Coca 2E", "2. Sprite 2E", "3. Orangina 2E","4. Lait 1,50E","5. Vodka 4E","6. Eau 1E"};
int choixActuel = 0;

void setup() {
    Serial.begin(9600);
    ecran.begin();
    sensor.begin();
    btnValider.begin();
    buzzer.begin();
    monServo.begin();

    ecran.afficher("Bienvenue !", "Tournez bouton");
    delay(2000);
    ecran.afficher("Boisson :", boissons[0]);
}



void loop() {
    int nouveauChoix = sensor.readSelection();
    Serial.println(nouveauChoix);
    if (nouveauChoix != -1) {
        choixActuel = nouveauChoix;
        ecran.afficher("Boisson :", boissons[choixActuel]);
        buzzer.beep(50);
    }

    if (btnValider.isPressed()) {
        buzzer.beep(50); 
        buzzer.beep(50);
        
        while(paiement.isPressed()==LOW){
        ecran.afficher("Payer par carte" , boissons[choixActuel]); 
        delay(2000);   
        }
        

        ecran.afficher("Preparation...", boissons[choixActuel]);
        monServo.distribuer(2000);
        
        ecran.afficher("Servi !", "Buvez bien !");
        delay(2000);
        
 
        ecran.afficher("Boisson :", boissons[choixActuel]);
    }
}
