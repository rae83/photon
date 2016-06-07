
// establishing the pin constants
const int potPin = A0;
const int irPin = A1;
const int red = D0;
const int green = D1;
const int blue = D2;
const int speakerPin = D3;

// note definitions
const int A = 440;
const int bb = 466;
const int B = 494;
const int C = 523;
const int Db = 554;
const int D = 587;
const int Eb = 622;
const int E = 659;
const int F = 698;
const int G = 784;
const int Ab = 830;
const int Aa = 880;
const int Bb = 932;
const int Cc = 1046;
const int Dd = 1175;

// pentatonic scale definitions
int aMinor[] = {A, B, C, D, E, G, Aa};
int bbMinor[] = {bb, C, Db, Eb, F, Ab, Bb};
int cMinor[] = {C, D, Eb, F, G, Bb, Cc};
int dMinor[] = {D, E, F, G, Aa, Cc, Dd};

// setting up an intial scale that will be changed based on pot-selected key
int scale[7];

// values to be read from
int irRead; // between 0 and 4095, determines note played
int potRead; // between 0 and 4095, determines key
int ledCode; // use map to put the pot reading to 1, 2, 3 or 4, each corresponding to a LED color


void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  potRead = analogRead(potPin);
  irRead = analogRead(irPin);
  delay(50); // any less than this and the sounds get muddled
  ledCode = map(potRead, 0, 3000, 1, 4);

  // changing the color to indicate what key you are in, changing the key
  switch(ledCode) {
    case 1:
      for (int i = 0; i < 7; i++) {
        scale[i] = aMinor[i];
      }
      analogWrite(red, 127);
      analogWrite(green, 0);
      analogWrite(blue, 0);
      break;
    case 2:
      for (int i = 0; i < 7; i++) {
        scale[i] = bbMinor[i];
      }
      analogWrite(green, 127);
      analogWrite(red, 0);
      analogWrite(blue, 0);
      break;
    case 3:
      for (int i = 0; i < 7; i++) {
        scale[i] = cMinor[i];
      }
      analogWrite(blue, 127);
      analogWrite(red, 0);
      analogWrite(green, 0);
      break;
    case 4:
      for (int i = 0; i < 7; i++) {
        scale[i] = dMinor[i];
      }
      analogWrite(red, 127);
      analogWrite(green, 127);
      analogWrite(blue, 127);
      break;
  }

  // playing tones based on hand position
  // highest value to change tone will be 3500, 500 increments
  if (irRead < 500) {
    Serial.println("Less than 500");
    noTone(speakerPin);
  }else if(irRead < 1000 && irRead >= 500) {
    tone(speakerPin, scale[0]);
    Serial.println("Less than 1000");
  }else if(irRead < 1400 && irRead >= 1000) {
    tone(speakerPin, scale[1]);
    Serial.println("Less than 1400");
  }else if(irRead < 1800 && irRead >= 1400) {
    tone(speakerPin, scale[2]);
    Serial.println("Less than 1800");
  }else if(irRead < 2200 && irRead >= 1800) {
    tone(speakerPin, scale[3]);
    Serial.println("Less than 2200");
  }else if(irRead < 2600 && irRead >= 2200) {
    tone(speakerPin, scale[4]);
    Serial.println("Less than 2600");
  }else if(irRead < 3000 && irRead >= 2600) {
    tone(speakerPin, scale[5]);
    Serial.println("Less than 3000");
  }else if(irRead < 3400 && irRead >= 3000) {
    tone(speakerPin, scale[6]);
    Serial.println("Less than 3400");
  }

}
