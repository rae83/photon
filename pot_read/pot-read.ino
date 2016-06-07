
const int potPin = A0;
const int distancePin = A1;

const int speakerPin = D0;
const int red = D1;
const int green = D2;


int reading; // between 0 and 4095
float volts; // between 0 and 3.3
float cm; // in cm right now

/*[(Vm/Vi) = Ri]
Vm = Measured Voltage
Vi = Volts per Inch (Scaling)
Ri = Range in inches*/

// 1" = 2.54cm


void setup() {

  Serial.begin(9600);

}

void loop() {
  reading = analogRead(distancePin);
  volts = reading * (3.3 / 4095);
  cm = 70 / volts - 6;
  Serial.println(cm / 2.54); // print in inches
  delay(100);

  tone(speakerPin, 440);
  delay(1000);
  noTone(speakerPin);

}
