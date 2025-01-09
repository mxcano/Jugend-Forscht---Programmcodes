void Set_Speed(int16_t new_speed) {

  // Definition der relevanten Variablen für die Funktion:
  static int16_t current_speed = 0;
  bool direction = 1;
  static uint16_t dac_value = 0;

  // Fallunterscheidung nach Art der Geschwindigkeitsänderung:
  if (new_speed > current_speed) {
    current_speed++;
  }
  if (new_speed < current_speed) {
    current_speed--;
  }

  // Abfrage ob Richtungsänderung vorgenommen werden muss:
  if (current_speed >= 0) {
    direction = 1;
  }
  else {
    direction = 0;
  }

  dac_value = map(abs(current_speed), 0, 1000, (int)dac_min_voltage, (int)dac_max_voltage);

  digitalWrite(F_R_SWITCH, direction);
  DAC.setVoltage(dac_value, false);

}