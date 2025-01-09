int16_t current_speed = 0; // aktueller speed-Wert
int16_t new_speed = +500; // neuer speed-Wert
const int16_t delay_time = 10; // Wartezeit (10 ms)

// Schleife zur rampenartigen Erhöhung des current_speed:
while (new_speed > current_speed) {
  current_speed++;

  delay(delay_time);
}

current_speed = new_speed;