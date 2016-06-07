// gyroscope example

const byte READ = 0b10000000;
const byte MULTI_READ = 0b01000000;
const byte CTRL1 = 0x20;
const byte ALL_AXIS_ON = 0b00001111;
const byte ACC_REFRESH_100Hz = 0b01100000;
const byte CTRL4 = 0x23;
const byte FULL_SCALE_2000DPS = 0b00000100;
const byte OUT_X_L = 0x28;
const byte OUT_Y_L = 0x2A;
const byte OUT_Z_L = 0x2C;

digitalWrite(CS_pin,LOW);
SPI.transfer(CTRL1);
SPI.transfer(ALL_AXIS_ON);
digitalWrite(CS_pin,HIGH);
digitalWrite(CS_pin,LOW);
SPI.transfer(CTRL4);
SPI.transfer(FULL_SCALE_2000DPS);
digitalWrite(CS_pin,HIGH);
