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

//initialisation du menu des boissons
const char* boissons[] = {"1. Coca 2E", "2. Sprite 2E", "3. Orangina 2E","4. Lait 1,50E","5. Vodka 4E","6. Eau 1E"};
int choixActuel = -1;
bool paiement_effect = false;


//initialisation des capteurs et actionneurs
void setup() {
    Serial.begin(9600);
    ecran.begin();
    sensor.begin();
    btnValider.begin();
    buzzer.begin();
    monServo.begin();
    
    choixActuel = sensor.readSelection();
    ecran.afficher("Bienvenue !", "Tournez bouton");
}


// affichage du choix de la boisson
void loop() {
    int nouveauChoix = sensor.readSelection(); 
    if (nouveauChoix != -1 && nouveauChoix != choixActuel) {
        choixActuel = nouveauChoix;
        ecran.afficher("Boisson :", boissons[choixActuel]);
        buzzer.beep(50);
    }

   if (btnValider.isPressed()) { // Validation du choix de la boisson
    buzzer.beep(50);
    ecran.afficher("Payer par carte", boissons[choixActuel]); //attente du paiement
    
    unsigned long tempsDebut = millis();
    paiement_effect = false;
    while (paiement_effect == false) {
        
        // Si on attend depuis plus de 7 secondes pour le paiement, on annule tout
        if (millis() - tempsDebut > 7000) {
            ecran.afficher("Temps ecoule", "Annulation");
            delay(2000);
            break; // On sort de la fonction (retour au début)
        }
        delay(50);
        if (paiement.isPressed()){
        paiement_effect = true;
        }
    }

    if (paiement_effect == false) {
    }
    else if (random(10) > 8) { // 1/10 chances d'avoir un paiement refusé
        ecran.afficher("Paiement refuse", "Reessayez");
        buzzer.beep(200); // Bip long d'erreur
        delay(2000);
    } 
    else {
        ecran.afficher("Paiement accepte !", "Preparation...");
        buzzer.beep(50);
        delay(100);
        buzzer.beep(50);
        delay(1000);

        ecran.afficher("Preparation...", boissons[choixActuel]);
        monServo.distribuer(2000);

        ecran.afficher("Servi !", "Buvez bien !");
        delay(3000);

        ecran.afficher("Bienvenue !", "Tournez bouton");
        }

    }
}    
        
        

