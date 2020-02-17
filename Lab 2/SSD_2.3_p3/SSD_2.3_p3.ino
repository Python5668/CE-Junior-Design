// SSD, single

int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

int SSDs = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  int t = 450;
  SSDs = 0x0C;// 00001100, 1
  updateShiftRegister();
  delay(t);
  SSDs = 0xB6;// 10110110, 2
  updateShiftRegister();
  delay(t);
  SSDs = 0x9E;// 10011110, 3
  updateShiftRegister();
  delay(t);
  SSDs = 0xCC;// 11001100, 4
  updateShiftRegister();
  delay(t);
  SSDs = 0xDA;// 11011010, 5
  updateShiftRegister();
  delay(t);
  SSDs = 0xFA;// 11111010, 6
  updateShiftRegister();
  delay(t);
  SSDs = 0x0E;// 00001110, 7
  updateShiftRegister();
  delay(t);
  SSDs = 0xFE;// 11111110, 8
  updateShiftRegister();
  delay(t);
  SSDs = 0xDE;// 11011100, 9
  updateShiftRegister();
  delay(t);
  SSDs = 0x7E;// 01111100, 0
  updateShiftRegister();
  delay(t);
}

void updateShiftRegister() {
  digitalWrite(latchPin, LOW); // disable latch/pass
  shiftOut(dataPin, clockPin, MSBFIRST, SSDs);
  digitalWrite(latchPin, HIGH); // rising edge latches/passes data through
}
