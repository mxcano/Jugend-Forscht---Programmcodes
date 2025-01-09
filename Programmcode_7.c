#include <Stepper.h>

#define HALL 1
#define PULSE 13 
#define DIRECTION 14
#define STEPPER_ZERO 42

// Schrittzahl für eine vollständige Umdrehung des Motors:
const uint16_t steps_per_revolution = 200 * 4;

// Schrittzahl pro vorbeidrehendem Magneten (≙ 1 mm):
const uint16_t part_revolution = steps_per_revolution / 25;

// Drehgeschwindigkeit des Schrittmotors (in U/min):
const uint16_t stepper_speed = 100;

volatile unsigned long stepper_count = 0; // Schrittzähler

// Länge der Linearführung in Schritten (l = 422 mm):
const float max_steps = (422 / 25) * steps_per_revolution; 

// Objektinitialisierung Schrittmotor:
Stepper linStepper(steps_per_revolution, PULSE, DIRECTION);


void setup() {

  pinMode(HALL, INPUT);
  pinMode(STEPPER_ZERO, INPUT); 

  linStepper.setSpeed(stepper_speed/10);

  // Referenzfahrt des Schrittmotors:
  while (digitalRead(STEPPER_ZERO) == LOW) {
    linStepper.step(-steps_per_revolution/100);
    stepper_count += steps_per_revolution/100;
  }
  
  linStepper.setSpeed(stepper_speed);
  linStepper.step(stepper_count);

}

void loop() {

  if (digitalRead(HALL) == HIGH) {
    // Richtungsänderung des Schrittmotors:
    if (stepper_count >= max_steps) {
      part_revolution = -part_revolution;
      stepper_count = 0;
    }
    linStepper.step(part_revolution);
    stepper_count += abs(part_revolution);
  }

}