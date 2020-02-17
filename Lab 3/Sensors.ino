// Example: thermistor
#include <LiquidCrystal.h>
int tempPin = 0;
//                BS E  D4 D5  D6  D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int tempReading = analogRead(tempPin);
  // This is OK
  double tempK = log(10000.0* (1024.0 / tempReading-1));
  tempK = 1 / ( 0.001129148 + (0.000234125 + (0.0000000087641 * tempK * tempK )) * tempK);
  float tempC = tempK - 273.15;             // Convert Kelvin to Celcius
  float tempF = (tempC * 9.0)/ 5.0 + 32.0;  // Convert Celcius to Fahrenheit
  // Display temperature in C
  lcd.setCursor(0, 0);
  lcd.print("Temp         C");
  // Display temperature in F
  //lcd.print("Temp         F");
  lcd.setCursor(6, 0);
  // Display temperature in C
  lcd.print(tempC);
  // Display temperature in F
  //lcd.print(tempF);
  delay(500);
}
