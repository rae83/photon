// stepper example
#include <Stepper.h>

const int pin1 = D0;
const int pin2 = D1;
const int pin3 = D2;
const int pin4 = D3;
const int pot = A0;

int reading = 0;
int potVal = 0;
int currentPosition;

Stepper motor(200, pin1, pin2, pin3, pin4);


void setup() {
  motor.setSpeed(30);
  Serial.begin(9600);
}


void loop() {
  reading = analogRead(pot);
  potVal = map(reading, 0, 4095, 0, 200);
  motor.step(potVal - currentPosition);
  currentPosition = potVal;

}
