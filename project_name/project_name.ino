#include "button.hpp"
#include "buzzer.hpp"
#include "rotary.hpp"
#include "lcd.hpp"
// #include "servo.hpp"  // À adapter


Button btnValider(13); 
Buzzer buzzer(12);
Lcd ecran;
RotarySensor sensor(A0, 3);

const char* boissons[] = {"1. Cafe", "2. The", "3. Chocolat"};
int choixActuel = 0;

void setup() {
    Serial.begin(9600);
    ecran.begin();
    sensor.begin();
    btnValider.begin();
    buzzer.begin();

    ecran.setColor(255, 255, 255);
    ecran.afficher("Bienvenue !", "Tournez bouton");
    delay(2000);
    ecran.afficher("Boisson :", boissons[0]);
}



void loop() {
    // --- 1. Gestion de la sélection (Rotation) ---
    int nouveauChoix = sensor.readSelection();
    Serial.println(nouveauChoix);
    if (nouveauChoix != -1) {
        choixActuel = nouveauChoix;
        Serial.print("Selection : ");
        Serial.print(choixActuel); // Affiche 0, 1 ou 2
        Serial.print(" | Boisson : ");
        Serial.print(boissons[choixActuel]); // Affiche "Cafe" etc.
        Serial.print(" | Valeur brute Capteur : ");
        Serial.println(analogRead(A0));
        ecran.afficher("Boisson :", boissons[choixActuel]);
    }

    // --- 2. Gestion de la validation (Appui) ---
    if (btnValider.isPressed()) {
        buzzer.beep(100); 
        
        // Changement de couleur pour indiquer la préparation (Vert)
        ecran.afficher("Preparation...", boissons[choixActuel]);
        
        delay(3000); // Temps de préparation
        
        ecran.afficher("Servi !", "Bonne degustation");
        delay(2000);
        
        // Retour à l'état initial (Blanc)
        ecran.afficher("Boisson :", boissons[choixActuel]);
    }
}
