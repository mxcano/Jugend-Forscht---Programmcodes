// min. und max. Eingangsspannung der Drehzahlregler (in V):
const float min_voltage = 1.2;
const float max_voltage = 2.6;

// min. und max. Eingangsspannung der Drehzahlregler (dac-Wert):
const float dac_min_voltage = min_voltage / (5 / 4095);
const float dac_max_voltage = max_voltage / (5 / 4095);

int16_t current_speed = 0; // aktueller speed-Wert
int16_t new_speed = +500; // neuer speed-Wert
const int16_t delay_time = 10; // Wartezeit (10 ms)

// Schleife zur rampenartigen Erhöhung des current_speed (dac-Wert):
while (new_speed > current_speed) {
  dac_value = map(abs(current_speed), 0, 1000, (int)dac_min_voltage, (int)dac_max_voltage);
  DAC.setVoltage(dac_value, false);  

  current_speed++;

  delay(delay_time);
}
  
DAC.setVoltage(dac_value, false);
current_speed = new_speed;