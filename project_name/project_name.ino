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

    if (nouveauChoix != -1) {
        choixActuel = nouveauChoix;
        // Mise à jour simple de l'écran
        ecran.afficher("Boisson :", boissons[choixActuel]);
        // Petit bruitage
        buzzer.beep(10); 
    }

    // --- 2. Gestion de la validation (Appui) ---
    if (btnValider.isPressed() == 0) {
        buzzer.beep(100); 
        
        // Changement de couleur pour indiquer la préparation (Vert)
        ecran.setColor(0, 255, 0); 
        ecran.afficher("Preparation...", boissons[choixActuel]);
        
        delay(3000); // Temps de préparation
        
        ecran.afficher("Servi !", "Bonne degustation");
        delay(2000);
        
        // Retour à l'état initial (Blanc)
        ecran.setColor(255, 255, 255);
        ecran.afficher("Boisson :", boissons[choixActuel]);
    }
}