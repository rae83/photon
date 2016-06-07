// LED connected to pin 9
const int ledPin = D0;
// button connected to pin 10
const int buttonPin = A0;
// State of the LED
boolean LED_on = false;
// State of the button
byte current_button = LOW;
// Previous state of the button
byte old_button = LOW;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the button pin as an input:
  pinMode(buttonPin, INPUT);
  // Set up serial communication
  Serial.begin(9600);
}
void loop()
{
  Serial.println("testing");
  while (1) // Fast loop…
  {
    // Read the state of the button
    current_button = digitalRead(buttonPin);
    if ((old_button == LOW)
    && (current_button == HIGH))
    {
      // LOW to HIGH transition:
      // we toggle the LED state
      LED_on = !LED_on;
    }
    // remember the state of the button
    old_button = current_button;
    // Update the LED pin
    if (LED_on == true)
    {
      digitalWrite(ledPin, HIGH);
    }
    else
    {
      digitalWrite(ledPin, LOW);
    }
  }
}

byte read_button(byte pin, byte ref_value)
{
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
