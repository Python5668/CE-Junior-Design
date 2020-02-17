byte data1 = 21; //value to transmit, binary 10101
byte data2 = 31; //binary 11111
byte data3 = 19; // binary 10011
int myPins[5] = {13,12,11,10,9};
byte mask = 1; // our bitmask

void setup() {
  pinMode(myPins[5],OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int i = 0;
  for (mask = 1; mask > 0; mask <<= 1){
    if (mask & data3) {
      digitalWrite(myPins[i], HIGH);
    }
    else {
      digitalWrite(myPins[i], LOW);
    }
    i++;
  }
}
