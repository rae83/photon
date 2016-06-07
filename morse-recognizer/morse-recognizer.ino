// button connected to pin A0
const int buttonPin = A0;
// output to run the motor
const int motor = D0;
// Length of a dash in ms
const int dash = 300;
// length of a dot in ms
const int dot = 100;
// state of the button this iteration
byte current_button = LOW;
// previous state of the button
byte old_button = LOW;
// start of a pressed event
unsigned long int start_high;
// end of a pressed event
unsigned long int stop_high;
// start of a non-pressed event
unsigned long int start_low;
// end of a non-pressed event
unsigned long int stop_low;

String collectdd = "";

int counter = 0;

// The setup() method runs once,
// when the sketch starts
void setup() {
  // initialize the button pin as an input:
  pinMode(buttonPin, INPUT);

  // initialize the output pin, D0
  pinMode(motor, OUTPUT);

  // Set up serial communication
  Serial.begin(9600);
}

void loop() {
  while (counter < 5) {
    // Read the current state
    current_button = read_button(buttonPin, old_button);
    // LOW -> HIGH transition
    if ((old_button == LOW) && (current_button == HIGH))
    {
      // Update timing
      start_high = millis();
      stop_low = start_high;
    } // end of low -> high

    // HIGH -> LOW transition
    if ((old_button == HIGH) && (current_button == LOW))
    {
      // Update timing
      stop_high = millis();
      start_low = stop_high;
      // detect dashs and dots
      if ((stop_high - start_high) >= dash)
      {
        Serial.print('-');
        collectdd += '-';
        counter++;
        /*Serial.print(collectdd[counter]);*/
      }
      else
      {
        if ((stop_high - start_high) >= dot)
        {
          Serial.print('.');
          collectdd += '.';
          counter++;
          /*Serial.print(collectdd[counter]);*/
        }
      }
    } // end of high -> low
    old_button = current_button;
    Particle.process();
  } // end of the while loop

  if (collectdd.length() == 5) {

    if (collectdd == "-----") { // 0
      analogWrite(motor, 0);
      Serial.print("Off");
    }else if(collectdd == ".----") { // 1
      analogWrite(motor, 25);
      Serial.print("1");
    }else if(collectdd == "..---") { // 2
      analogWrite(motor, 50);
      Serial.print("2");
    }else if(collectdd == "...--") { // 3
      analogWrite(motor, 75);
      Serial.print("3");
    }else if(collectdd == "....-") { // 4
      analogWrite(motor, 100);
      Serial.print("4");
    }else if(collectdd == ".....") { // 5
      analogWrite(motor, 125);
      Serial.print("5");
    }else if(collectdd == "-....") { // 6
      analogWrite(motor, 150);
      Serial.print("6");
    }else if(collectdd == "--...") { // 7
      analogWrite(motor, 175);
      Serial.print("7");
    }else if(collectdd == "---..") { // 8
      analogWrite(motor, 200);
      Serial.print("8");
    }else if(collectdd == "----.") { // 9
      analogWrite(motor, 225);
      Serial.print("9");
    }
    counter = 0;
    collectdd = "";
  } // end of if (counter == 5) loop
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
