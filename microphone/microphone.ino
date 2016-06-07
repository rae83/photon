// microphone program

const int micPin = A0;
int reading;

void setup() {
  Serial.begin(115200);
}

void loop() {
  reading = analogRead(micPin);
  int counter = 0;
  if (reading > 3400) {
    while (counter < 140) {
      reading = analogRead(micPin);
      Serial.write(reading / 16);
      counter++;
    }
  }
}
