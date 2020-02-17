#include <SimpleDHT.h>

SimpleDHT11 dht11;

int SSDs = 0; // global variable for the 'updateShiftRegister[MSB/LSB/Unit]' functions 
int dataPin = 12;
int latchPin = 11;
int clockPin = 9;
int pin7 = 7;
int pin6 = 6;
int pin4 = 4;
int pinDHT11 = 2;
byte temperature = 0;
byte humidity = 0;
byte data[40] = {0};
int toggle = 0; // global variable for: void loop(), updateShiftRegister[MSB/LSB/Unit](),
// and ISR(), functions.
//                0     1     2     3     4     5     6     7     8     9
int HexVals[] = {0x7E, 0x0C, 0XB6, 0x9E, 0XCC, 0xDA, 0xFA, 0x0E, 0xFE, 0xDE};
int t = 2; // time in miliseconds for the delay(s) in all 3 updateShiftRegister functions.

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pinDHT11, INPUT);
  
  noInterrupts(); // Stop any other interrupts
  TCCR1A = 0; // Resets Timer/Counter1 Control Register A
  TCCR1B = 0; // Resets Timer/Counter1 Control Register B
  TCNT1 = 0; // Resests Timer/Counter1
  OCR1A = 62500; // Output Compare Register // LI: OCR0A=256
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12); //CS12==2, move 1 to the left by two bits,     // LI: change the prescalor to clk/1024
  // OR TCCR1B, replace TCCR1B with the new result. This is the same
  // as SET the CS12 bit to 1.
  TCCR1B |= (1 << CS10); //SET the CS10 bit to 1.
  TIMSK1 |= (1 << OCIE1A); // use number match to trigger interrupts
  interrupts();
}

void loop() {
  // void loop constantly extracts data from DHT11 and turns on & off the Seven Segment Displays.
  dht11.read(pinDHT11, &temperature, &humidity, data); // Read the data
  switch (toggle) // toggle between displaying temp and humidity 
  {
    case 0: // Case Temperature
      digitalWrite(pin7, LOW);
      updateShiftRegisterMSB();
      digitalWrite(pin7, HIGH);

      digitalWrite(pin6, LOW);
      updateShiftRegisterLSB();
      digitalWrite(pin6, HIGH);

      digitalWrite(pin4, LOW);
      updateShiftRegisterUnit();
      digitalWrite(pin4, HIGH);
      break;
      
    case 1: // Case Humidity
      digitalWrite(pin7, LOW);
      updateShiftRegisterMSB();
      digitalWrite(pin7, HIGH);

      digitalWrite(pin6, LOW);
      updateShiftRegisterLSB();
      digitalWrite(pin6, HIGH);

      digitalWrite(pin4, LOW);
      updateShiftRegisterUnit();
      digitalWrite(pin4, HIGH);
      break;
  }
}

ISR(TIMER1_COMPA_vect) {
  // This interuption function acts as a toggle/switch
  // for the switch-statement in the void loop.
  if (toggle == 0) { toggle = 1;}
  else { toggle = 0;}
}

void updateShiftRegisterMSB() {
  // This function changes the 1st segment number on the board
  // according to what value is given by the DHT11.
  int MSB = 0;
  
  if (toggle == 0) { MSB = temperature / 10;}
  else { MSB = humidity / 10;}
  
  SSDs = HexVals[MSB]; // Uses 'MSB' as an indice for the global array 'hex' 
  // to select the correct hex value.
  
  digitalWrite(latchPin, LOW); // disable latch/pass
  shiftOut(dataPin, clockPin, MSBFIRST, SSDs);
  digitalWrite(latchPin, HIGH); // rising edge latches/passes data through
  delay(t);
}

void updateShiftRegisterLSB() {
  // This function changes the 2nd segment number on the board
  // according to what value is given by the DHT11.
  int LSB = 0;
  
  if (toggle == 0) { LSB = temperature % 10;}
  else { LSB = humidity % 10;}
  
  SSDs = HexVals[LSB]; // Uses 'LSB' as an indice for the global array 'hex' 
  // to select the correct hex value.  
  
  digitalWrite(latchPin, LOW); // disable latch/pass
  shiftOut(dataPin, clockPin, MSBFIRST, SSDs);
  digitalWrite(latchPin, HIGH); // rising edge latches/passes data through
  delay(t);
}

void updateShiftRegisterUnit() {
  // This function changes the unit on the board
  // according to what toggle/case we are in.
  byte letter = 0;
  
  if (toggle == 0) {
    letter = B01110010; // Letter C for celsius
  }
  else {
    letter = B11100110; // Letter P for percent
  }
  digitalWrite(latchPin, LOW); // disable latch/pass
  shiftOut(dataPin, clockPin, MSBFIRST, letter);
  digitalWrite(latchPin, HIGH); // rising edge latches/passes data through
  delay(t);
}
