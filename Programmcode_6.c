#include <Stepper.h>

#define HALL 1
#define PULSE 13 
#define DIRECTION 14

// Schrittzahl für eine vollständige Umdrehung des Motors:
const uint16_t steps_per_revolution = 200 * 4;

// Schrittzahl pro vorbeidrehendem Magneten (≙ 1 mm):
const uint16_t part_revolution = steps_per_revolution / 25;

// Drehgeschwindigkeit des Schrittmotors (in U/min):
const uint16_t stepper_speed = 100;

// Objektinitialisierung Schrittmotor:
Stepper linStepper(steps_per_revolution, PULSE, DIRECTION);

void setup() {
  
  pinMode(HALL, INPUT);

}

void loop() {

  if (digitalRead(HALL) == HIGH) {
    linStepper.step(part_revolution);
  }

}