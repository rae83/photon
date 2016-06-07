

const int led = D0;

void setup() {
  // Tell photon we want to use D0 line for digital output
  pinMode(led, OUTPUT);

  // Begin listening to serial port
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    char b = Serial.available();
    Serial.write(b);
  }
}

void dot() {
  digitalWrite(led, HIGH);
  delay(300);
  digitalWrite(led, LOW);
  delay(300);
}

void dash() {
  digitalWrite(led, HIGH);
  delay(900);
  digitalWrite(led, LOW);
  delay(300);
}
