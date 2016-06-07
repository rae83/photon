// voice recorder

int16_t recordings[24000];
const int num_recordings = 24000;
const int micPin = A0;

void setup() {
  Serial.begin(9600);
  setADCSampleTime(ADC_SampleTime_3Cycles);
}

void loop() {
  // sampling loop
  Serial.println("recording...");
  for (int i = 0; i<num_recordings; i++) {
    recordings[i] = analogRead(micPin);
    delayMicroseconds(108);
  }
  delay(1000);

  Serial.println("replaying...");
  //replay loop
  for (int i = 0; i<num_recordings; i++) {
    analogWrite(DAC, recordings[i]);
    delayMicroseconds(120);
  }
  delay(1000);

}
