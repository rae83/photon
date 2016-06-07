// Motor control
const int motorEnablePin = D0;
const int leftSidePin = D1;
const int rightSidePin = D2;
const int encoderPin = A0;
// old state of the encoder
boolean old_state = LOW;
// current state of the encoder
boolean current_state = LOW;
// current transition count
int pulse_count;
// number of transition for a full turn
const int full_turn_count = 275;
bool forwardD = true;

void setup()
{
  // configure the motor pins
  pinMode(motorEnablePin,OUTPUT);
  pinMode(leftSidePin,OUTPUT);
  pinMode(rightSidePin,OUTPUT);
  // Motor is off going forward
  analogWrite(motorEnablePin,0);
  digitalWrite(leftSidePin, HIGH);
  digitalWrite(rightSidePin, LOW);
  // configure the photo-transistor pin
  pinMode(encoderPin,INPUT);
}
void loop()
{
  // reset the pulse counter
  pulse_count = 0;
  // start the motor at 20% speed
  analogWrite(motorEnablePin,51);
  // loop until we get the correct count
  while (pulse_count < full_turn_count)
  {
    // read the state of the photo-transistor
    current_state = digitalRead(encoderPin);
    if (current_state != old_state)
    {
      // we detected a transition
      pulse_count++;
      /*Serial.println(pulse_count);*/
      // delay here is problem with de-bounding
    }
    old_state = current_state;
  }
  analogWrite(motorEnablePin,0);
  delay(5000);
  // switch off the motor
  if (forwardD) {
    reverse();
    forwardD = false;
  }else{
    forward();
    forwardD = true;
  }
  // wait a bit
}

void forward() {
  analogWrite(motorEnablePin, 0);
  digitalWrite(leftSidePin, HIGH);
  digitalWrite(rightSidePin, LOW);
  analogWrite(motorEnablePin, 51);
  delay(500);
}

void reverse() {
  analogWrite(motorEnablePin, 0);
  digitalWrite(leftSidePin, LOW);
  digitalWrite(rightSidePin, HIGH);
  analogWrite(motorEnablePin, 51);
  delay(500);
}
