// keypad digit display
// to avoid repeated characters, remember the last pattern that was pressed!
// read pattern from PORTC, from that pattern, press the key that has been pressed

#define PORTA (GPIOA -> ODR)
#define PINA (GPIOA -> IDR)
#define PORTB (GPIOB -> ODR)
#define PINB (GPIOB -> IDR)
#define PORTC (GPIOC -> ODR)
#define PINC (GPIOC -> IDR)

const char conversion_table[7][3] =
  {{'!', '!', '!'},
  {'!', '!', '!'},
  {'!', '!', '!'},
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}};
const byte character_patterns_table[7][3] =
  {{10, 10, 10},
  {10, 10, 10},
  {10, 10, 10},
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9},
  {11, 0, 12}};

const int16_t portB_message_mask = 0b0000000011111000;
const int16_t pinc_mask = 0b0000000000101100;
const int16_t char_patterns[13][7] = {
                        {~0b0000000001110000, //0
                         ~0b0000000010001000,
                         ~0b0000000010011000,
                         ~0b0000000010101000,
                         ~0b0000000011001000,
                         ~0b0000000010001000,
                         ~0b0000000001110000},
                        {~0b0000000000100000, //1
                         ~0b0000000001100000,
                         ~0b0000000000100000,
                         ~0b0000000000100000,
                         ~0b0000000000100000,
                         ~0b0000000000100000,
                         ~0b0000000001110000},
                        {~0b0000000001110000, //2
                         ~0b0000000010001000,
                         ~0b0000000000001000,
                         ~0b0000000000110000,
                         ~0b0000000001000000,
                         ~0b0000000010000000,
                         ~0b0000000011111000},
                        {~0b0000000011111000, //3
                         ~0b0000000000001000,
                         ~0b0000000000010000,
                         ~0b0000000000110000,
                         ~0b0000000000001000,
                         ~0b0000000010001000,
                         ~0b0000000001110000},
                        {~0b0000000000010000, //4
                         ~0b0000000000110000,
                         ~0b0000000001010000,
                         ~0b0000000010010000,
                         ~0b0000000011111000,
                         ~0b0000000000010000,
                         ~0b0000000000010000},
                        {~0b0000000011111000, //5
                         ~0b0000000010000000,
                         ~0b0000000011110000,
                         ~0b0000000000001000,
                         ~0b0000000000001000,
                         ~0b0000000010001000,
                         ~0b0000000001110000},
                        {~0b0000000000111000, //6
                         ~0b0000000001000000,
                         ~0b0000000010000000,
                         ~0b0000000011110000,
                         ~0b0000000010001000,
                         ~0b0000000010001000,
                         ~0b0000000001110000},
                        {~0b0000000011111000, //7
                         ~0b0000000000001000,
                         ~0b0000000000010000,
                         ~0b0000000000100000,
                         ~0b0000000001000000,
                         ~0b0000000001000000,
                         ~0b0000000001000000},
                        {~0b0000000001110000, //8
                         ~0b0000000010001000,
                         ~0b0000000010001000,
                         ~0b0000000001110000,
                         ~0b0000000010001000,
                         ~0b0000000010001000,
                         ~0b0000000001110000},
                        {~0b0000000001110000, //9
                         ~0b0000000010001000,
                         ~0b0000000010001000,
                         ~0b0000000001111000,
                         ~0b0000000000001000,
                         ~0b0000000000010000,
                         ~0b0000000011100000},
                        {~0b0000000000100000, //!
                         ~0b0000000000100000,
                         ~0b0000000000100000,
                         ~0b0000000000100000,
                         ~0b0000000000100000,
                         ~0b0000000000000000,
                         ~0b0000000000100000},
                        {~0b0000000000100000,
                         ~0b0000000010101000, //*
                         ~0b0000000001110000,
                         ~0b0000000011111000,
                         ~0b0000000001110000,
                         ~0b0000000010101000,
                         ~0b0000000000100000},
                        {~0b0000000001010000, //#
                         ~0b0000000001010000,
                         ~0b0000000011111000,
                         ~0b0000000001010000,
                         ~0b0000000011111000,
                         ~0b0000000001010000,
                         ~0b0000000001010000}};

const int rows[7] = {A3, A4, A5, DAC, WKP, RX, TX};
const int row_length = 7;
const int keyboard[3] = {A0, A1, A2};
const int keyboard_count = 4;

void setup() {
  Serial.begin(9600);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
}

// wrap inner loop in a another counter loop to make cycling digits stay longer

int current_char = 0;
void loop(){

  for (int j = 0; j < row_length;  j++){
    pinMode(rows[j],OUTPUT);
    digitalWrite(rows[j], HIGH);
    clean_update(PORTB, portB_message_mask, char_patterns[current_char][j]);
    int pressed = PINC & pinc_mask;
    int column = -1;
    Serial.println(pressed);
    if (pressed == 4){
      column = 1;
      Serial.println("second column");
    }
    if (pressed == 8){
      column = 0;
      Serial.println("first column");
    }
    if (pressed == 32){
      column = 2;
      Serial.println("third column");
    }
    if (column != -1) {
      current_char = character_patterns_table[j][column];
    }
    delay(1);
    digitalWrite(rows[j], LOW);
    pinMode(rows[j],INPUT);
  }

}

inline void clean_update(__IO uint32_t &target_register, int mask, int value_to_update){
  target_register = (target_register & ~mask) | (value_to_update & mask);
}
