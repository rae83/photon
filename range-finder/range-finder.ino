
const int potPin = A0;
const int distancePin = A1;

const int speakerPin = D0;
const int red = D1;
const int green = D2;

int irRead; // between 0 and 4095
int potRead; // also between 0 and 4095
float volts; // between 0 and 3.3
float cm; // distance in cm
float target; // the target distance, as dictated by the pot
int resistance; // resistance from the pot, used to determine distance

void setup() {
  Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  irRead = analogRead(distancePin);
  volts = irRead * (3.3 / 4095);
  cm = 70 / volts - 6;

  potRead = analogRead(potPin);
  resistance = potRead * (3.3 / 4095);
  target = 15 + 70 / (resistance + 1) - 6; // same conversion to distance, but adding 15 to adjust for IRsensor accuracy

  if ((cm - target) < 2 && (target - cm) < 2) {
    // beep and turn both lights off
    analogWrite(green, 0);
    analogWrite(red, 0);
    tone(speakerPin, 440);
    delay(500);
    noTone(speakerPin);
  }else if (cm > target) {
    // then farther away than target, so light green
    analogWrite(red, 255 * (cm - target) / target); // turn red on, brightness relative to distance -- closer = duller
    analogWrite(green, 0);
  }else{
    //closer to sensor than target, so light red
    analogWrite(red, 0); // turn red off
    analogWrite(green, 255 * (target - cm) / target); // brightness relative to distance -- closer = duller
  }
}
