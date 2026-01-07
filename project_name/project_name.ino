#include "button.hpp"
#include "buzzer.hpp"
// #include "rotary.hpp" // À adapter sur le même modèle que Buzzer
// #include "servo.hpp"  // À adapter

// Instanciation des objets (Exemple: Bouton sur D2, Buzzer sur D3)
Button btnValider(13); 
Buzzer buzzer(12);

void setup() {
    btnValider.begin();
    buzzer.begin();
}

void loop() {
    // Exemple d'utilisation
    if (btnValider.isPressed() == 0) {
        buzzer.beep(100); // Bip sonore
        delay(500); // Anti-rebond simple
    }
}