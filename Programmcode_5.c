const float i = 10.8 / 4.91; // Übersetzungsverhältnis Motoren
const float n = 2 // Wert zur Empfindlichkeit im Ausdruck d
const uint16_t min_poti = 1850; // Potistellung (ohne Schnurspannung)
const uint16_t max_poti = 350; // Potistellung (max. Schnurspannung)

// optimale Potistellung:
const uint16_t opt_poti = (min_poti + max_poti) / 2;

// Adjust_Win_Speed()-Funktion:
void Adjust_Win_Speed() {

  // aktuelle Potistellung:
  current_poti = analogRead(WIN_POT);
  
  // Formel zur Berechnung von new_win_speed:
  new_win_speed = -1 * (1/i * ((n-1) + (current_poti/opt_poti)) / n * new_zyl_speed);

}