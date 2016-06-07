#define PORTB (GPIOB -> ODR)
#define PINB (GPIOB -> IDR)

const int scanning_pattern_mask =  0b00000000111000;
const int greenLED = D2;
const int redLED = D4;
const int blueLED = D3;
const int scanning_pattern_count = 6;
int scanning_patterns[6] = {0b00000000001000,  0b00000000011000,  0b00000000010000,  0b00000000011000,  0b00000000100000,  0b00000000101000};



void setup() {
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  for (int j = 0; j < scanning_pattern_count; j++){
    PORTB = (PORTB & ~scanning_pattern_mask) | (scanning_patterns[j] & scanning_pattern_mask);
    delay(100);
  }

}

/*inline void clean_update(_IO uint32_t &target_register, int mask, int value_to_update){
  target_register = (target_register & ~mask) | (value_to_update & mask);
}*/
