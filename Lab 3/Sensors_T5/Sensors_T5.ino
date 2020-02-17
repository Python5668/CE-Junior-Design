/*// Task 5: DHT11

  #include <LiquidCrystal.h>
  #include <SimpleDHT.h>
  //                BS E  D4 D5  D6  D7
  LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
  // for DHT11,
  //    VCC: 5V or 3V
  //    GND: GND
  //    DATA: 2
  int pinDHT11 = 2;
  SimpleDHT11 dht11;
  void setup() {
  lcd.begin(16, 2);
  }

  void loop() {
  lcd.setCursor(0, 0);
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  dht11.read(pinDHT11, &temperature, &humidity, data);
  lcd.print((int)temperature); lcd.print(" *C, ");
  lcd.print((int)humidity); lcd.print(" %");
  // DHT11 sampling rate is 0.5Hz
  delay(2000);
  }*/

/*
#include <SimpleDHT.h>

// for DHT11,
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 4;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // start working...
  Serial.println("===============================");
  Serial.println("Sample DHT11...");

  // read with raw sample data.
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    Serial.print("Read DHT11 failed\n");
    return;
  }

  Serial.print("Sample RAW Bits: ");
  for (int i = 0; i < 40; i++) {
    Serial.print((int)data[i]);
    if (i > 0 && (( i + 1 ) % 4 ) == 0) {
      Serial.print(' ');
    }
  }
  Serial.println("");

  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");

  // DHT11 sampling rate is 1Hz
  delay(1000);
}*/

  #include <LiquidCrystal.h>
  #include <SimpleDHT.h>

  SimpleDHT11 dht11;
  LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

  int pinDHT11 = 4;

  void setup() {
  lcd.begin(16, 2);
  }

  void loop() {
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  dht11.read(pinDHT11, &temperature, &humidity, data);

  lcd.setCursor(0, 0);
  lcd.print("Temp     C");
  lcd.setCursor(6, 0);
  lcd.print((int)temperature);

  lcd.setCursor(0, 1);
  lcd.print("Humidity     %");
  lcd.setCursor(10, 1);
  lcd.print((int)humidity);

  delay(1000);
  }
