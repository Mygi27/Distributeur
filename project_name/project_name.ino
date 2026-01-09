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
int choixActuel = 0;

//initialisation des capteurs et actionneurs
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
        buzzer.beep(50);
        delay(500);
        buzzer.beep(50);
        delay(1000);
        ecran.afficher("Servi !", "Buvez bien !");
        delay(3000);

        ecran.afficher("Preparation...", boissons[choixActuel]);
        monServo.distribuer(2000);
        
        ecran.afficher("Servi !", "Buvez bien !");
        delay(2000);
        
        ecran.afficher("Bienvenue !", "Tournez bouton");
        delay(2000);
        ecran.afficher("Boisson :", boissons[choixActuel]);
    }

    /*

    catch (int erreur){
        switch(erreur){
            case 1 : Serial.println("Boisson hors index");
            nouveauChoix = 6;
            break;
            case 2 : Serial.println("nouveauChoix"); break
            default: Serial.println("nouveauChoix");
        } }
     */
}
