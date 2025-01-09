void Set_Win_Speed(int16_t new_speed) {

  // Fallunterscheidung der Geschwindigkeitsänderung:
  if (new_speed >= current_speed){
    
    // rampenartigen Erhöhung des current_speed (dac-Wert):
    while (new_speed > current_speed) {

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

      current_speed++;
      delay(delay_time);
    }
  }

  else{
    while (new_speed < current_speed) {
      
      if (current_speed >= 0) {
        direction = 1;
      }
      else {
        direction = 0;
      }

      dac_value = map(abs(current_speed), 0, 1000, (int)dac_min_voltage, (int)dac_max_voltage);

      digitalWrite(F_R_SWITCH, direction);
      DAC.setVoltage(dac_value, false);
          
      current_speed--;
      delay(delay_time);
    }
  }

  if (current_speed >= 0) {
    direction = 1;
  }
  else {
    direction = 0;
  }

  digitalWrite(F_R_SWITCH, direction);
  DAC.setVoltage(dac_value, false);
  current_speed = new_speed;

}