// h-bridge

const int outPin = D0;
const int pin1 = D1;
const int pin2 = D2;

const int photoPin = A0;
int photoRead;

bool running = false;
bool forwardTest = true;

void setup() {
  Serial.begin(9600);
  pinMode(outPin, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(photoPin, INPUT);
}

void loop() {
  photoRead = digitalRead(photoPin);
  Serial.println(photoRead);
  delay(500);

  if (Serial.available() > 0) {
    char b = Serial.read();
    Serial.write(b);

    switch(b) {
      case 'o':
        running = true;
        if (forwardTest) {
          forward();
        }else{
          reverse();
        }
        break;
      case 'f':
        if (running) {
          forward();
        }
        forwardTest = true;
        break;
      case 'b':
        if (running) {
          reverse();
        }
        forwardTest = false;
        break;
      case 's':
        breaking();
        running = false;
        break;
      }
    }
}

void forward() {
  digitalWrite(outPin, LOW);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(outPin, HIGH);
  delay(500);
  forwardTest = true;
}

void reverse() {
  digitalWrite(outPin, LOW);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  digitalWrite(outPin, HIGH);
  delay(500);
  forwardTest = false;
}

void breaking() {
  digitalWrite(outPin, LOW);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(outPin, HIGH);
  delay(500);
}
