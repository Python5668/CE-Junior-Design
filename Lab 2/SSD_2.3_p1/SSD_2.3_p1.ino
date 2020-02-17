int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte leds = 0x01; // 0x indicates a HEX number. 0x01 is actually 0000 0001 in binary.

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  leds = 0x01;
  updateShiftRegister();
  delay(500);
  for (int i=0; i<8; i++){
    leds = leds << 1; // 'left shift' the '1' in the byte
    updateShiftRegister();
    delay(500);
  }
}

void updateShiftRegister() {
  digitalWrite(latchPin, LOW); // disable latch/pass
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH); // rising edge latches/passes data through
}
