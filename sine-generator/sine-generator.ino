// sine generator

#include <math.h>

float PI = 3.1415926535;
int num_samples = 128;
int sine_samples[128];

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < num_samples; i++) {
    sine_samples[i] = 2047*(sin(2*PI*i/(1.0*num_samples)) + 1.0);
  }
}

void loop() {
  for (int i = 0; i < num_samples; i++) {
    analogWrite(DAC, sine_samples[i]);
    Serial.println(sine_samples[i]);
  }
}
