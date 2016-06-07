// for incoming serial data
int incomingByte = 0;

// LED connected to digital pin 0
const int ledPin = D0;

void setup() {
  // opens serial port, sets data rate to 9600 bps
  Serial.begin(9600);

  // initialize the digital pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    if (incomingByte == '1') {
      // morse sequence for 1
      analogWrite(ledPin, 26);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 26);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 26);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 26);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 26);
      delay(900);
      analogWrite(ledPin, 0);
      delay(900);
    }
    if (incomingByte == '2') {
      // morse sequence for 2
      analogWrite(ledPin, 53);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 52);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 52);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 52);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 52);
      delay(900);
      analogWrite(ledPin, 0);
      delay(900);
    }
    if (incomingByte == '3') {
      // morse sequence for 3
      analogWrite(ledPin, 78);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 78);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 78);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 78);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 78);
      delay(900);
      analogWrite(ledPin, 0);
      delay(900);
    }
    if (incomingByte == '4') {
      // morse sequence for 4
      analogWrite(ledPin, 104);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 104);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 104);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 104);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 104);
      delay(900);
      analogWrite(ledPin, 0);
      delay(900);
    }
    if (incomingByte == '5') {
      // morse sequence for 5
      analogWrite(ledPin, 130);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 130);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 130);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 13);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 130);
      delay(300);
      analogWrite(ledPin, 0);
      delay(900);
    }
    if (incomingByte == '6') {
      // morse sequence for 6
      analogWrite(ledPin, 156);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 156);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 156);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 156);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 156);
      delay(300);
      analogWrite(ledPin, 0);
      delay(900);
    }
    if (incomingByte == '7') {
      // morse sequence for 7
      analogWrite(ledPin, 182);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 182);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 182);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 182);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 182);
      delay(300);
      analogWrite(ledPin, 0);
      delay(900);
    }
    if (incomingByte == '8') {
      // morse sequence for 8
      analogWrite(ledPin, 208);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 208);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 208);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 208);
      delay(300);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 208);
      delay(300);
      analogWrite(ledPin, 0);
      delay(900);
    }
    if (incomingByte == '9') {
      // morse sequence for 9
      analogWrite(ledPin, 234);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 234);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 234);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 234);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 234);
      delay(300);
      analogWrite(ledPin, 0);
      delay(900);
    }
    if (incomingByte == '0') {
      // morse sequence for 0
      analogWrite(ledPin, 0);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 0);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 0);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 0);
      delay(900);
      analogWrite(ledPin, 0);
      delay(300);
      analogWrite(ledPin, 0);
      delay(900);
      analogWrite(ledPin, 0);
      delay(900);
    }
  }
}
