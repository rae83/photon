
// lidar example
#include <Stepper.h>

const int pin1 = D1;
const int pin2 = D2;
const int pin3 = D3;
const int pin4 = D4;
const int irPin = A1;

const int servPin = D0;
Servo servo;

int direction = 1; // alternate between 1 and -1, sets the direction of turn for sweep
int counter = 0; // goes from 0 -> 50, then back to 0
int sensorVal; // between 0 and 4095
int angle = 0; // in 1/10 degree, so between 0 and 900
float volts; // between 0 and 5
float cm; // volts converted to cm = 70 / volts - 6
float mm;
int range; // int casting of mm --> (int) mm

Stepper motor(200, pin1, pin2, pin3, pin4); // constructing the stepper motor object


void setup() {
  motor.setSpeed(30);
  pinMode(servPin, OUTPUT);
  servo.attach(servPin);
  Serial.begin(9600);
}


void loop() {
  motor.step(1);
  servo.write(90);
  delay(100);
  servo.write(0);
  delay(100);
}
