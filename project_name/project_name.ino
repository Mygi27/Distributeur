#include "button.hpp"
#include "buzzer.hpp"
// #include "rotary.hpp" // À adapter sur le même modèle que Buzzer
// #include "servo.hpp"  // À adapter

// Instanciation des objets (Exemple: Bouton sur D2, Buzzer sur D3)
Button btnValider(2); 
Buzzer buzzer(3);

void setup() {
    btnValider.begin();
    buzzer.begin();
}

void loop() {
    // Exemple d'utilisation
    if (btnValider.isPressed()) {
        buzzer.beep(100); // Bip sonore
        delay(500); // Anti-rebond simple
    }
}