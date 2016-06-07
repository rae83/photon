
// lidar example
#include <Stepper.h>

const int pin1 = D0;
const int pin2 = D1;
const int pin3 = D2;
const int pin4 = D3;
const int irPin = A1;

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
  Serial.begin(9600);
}


void loop() {
  // for each step, send <angle>, <range>. to serial
  // angle should be in 1/10 of a degree - so each time, it adds 18 until we get to 900 (50 iterations)
  // range is in mm (integer)
  // wait for return character from processing program before doing the next step

    if (Serial.available()) {
      Serial.read(); // to pop off the character sent from processing to Serial
      Serial.read();
      sensorVal = analogRead(irPin); // get the value (range 0 - 4095) from the IR sensor
      /*Serial.println(sensorVal);*/

      volts = sensorVal * 3.3 / 4095; // b/c attached to a 5v pin
      cm = 70 / volts - 6; // converting volts to mm (original code converted to cm with 70/volts)
      mm = cm * 10;
      range = (int) mm; // cast the mm into an int

      Serial.print(angle);
      Serial.print(",");
      Serial.print(range);
      Serial.print(".");

      motor.step(direction);
      angle += 18 * direction;
      counter += 1;
      /*Serial.print("Counter:" + counter);*/

      if (counter == 50) {
        direction = -direction;
        counter = 0;
      }

      delay(50);
    }

}
