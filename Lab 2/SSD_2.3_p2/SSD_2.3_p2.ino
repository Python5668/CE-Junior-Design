// SSD, single

int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte SSDs = 0x7f; // in binary, it is 0111 1111, which only turns off G, will display 0

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  updateShiftRegister();
  delay(500);
}

void updateShiftRegister() {
  digitalWrite(latchPin, LOW); // disable latch/pass
  shiftOut(dataPin, clockPin, MSBFIRST, SSDs);
  digitalWrite(latchPin, HIGH); // rising edge latches/passes data through
}
