// jack in the box code - servo and spst switch
Servo servo;
const int servoPin = D0;
const int buttonPin = A0;
bool servo_up = false;
int position = 0;
int pos = 0;

byte current_button = LOW;
byte old_button = LOW;


void setup() {
  // attach servo
  servo.attach(servoPin);
  // initialize the button pin as an input:
  pinMode(buttonPin, INPUT);
  // Set up serial communication
  Serial.begin(9600);
}

void loop() {
  while (1)
  {
    // Read the state of the button
    current_button = read_button(buttonPin, old_button);
    if ((old_button == LOW)
    && (current_button == HIGH))
    {
      // transition state of servo
      servo_up = !servo_up;
      Serial.println("button pressed");
    }
    // remember the state of the button
    old_button = current_button;
    // Update the servo position
    if (servo_up == true)
    {
      servo.write(45);
    }
    else
    {
      servo.write(0);
    }
  }
}

byte read_button(byte pin, byte ref_value) {
  // observed the state of the button
  byte current_button = digitalRead(pin);
  // There is a LOW -> HIGH transition
  // or a HIGH -> LOW transition
  if (((ref_value == LOW)
  && (current_button == HIGH))
  || ((ref_value == HIGH)
  && (current_button == LOW)))
  {
    // wait for a while (5ms)
    delay(5);
    // update the state of the button
    current_button = digitalRead(pin);
  }
  return(current_button);
}
