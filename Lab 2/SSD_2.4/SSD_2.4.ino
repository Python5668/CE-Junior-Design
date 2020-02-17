int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int pin7 = 7;
int pin6 = 6;
int pin5 = 5;
int pin4 = 4;

byte SSDs = 0; // create a byte for future use.

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin4, OUTPUT);
}
void loop() {
  SSDs = 0xB6;// 10110110, 2
  digitalWrite(pin7, LOW);
  updateShiftRegister();
  digitalWrite(pin7, HIGH);
  SSDs = 0x7E;// 01111100, 0
  digitalWrite(pin6, LOW);
  updateShiftRegister();
  digitalWrite(pin6, HIGH);
  SSDs = 0xFE;// 11111110, 8
  digitalWrite(pin5, LOW);
  updateShiftRegister();
  digitalWrite(pin5, HIGH);
  SSDs = 0xCC;// 11001100, 4
  digitalWrite(pin4, LOW);
  updateShiftRegister();
  digitalWrite(pin4, HIGH);
}

void updateShiftRegister() {
  digitalWrite(latchPin, LOW); // disable latch/pass
  shiftOut(dataPin, clockPin, MSBFIRST, SSDs);
  digitalWrite(latchPin, HIGH); // rising edge latches/passes data through
  delay(6);
}
