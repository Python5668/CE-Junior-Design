// Task 6: TMP36 temperature sensor IC
#include <LiquidCrystal.h>
//                BS E  D4 D5  D6  D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
const int sensorPin = A0;
void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal/1024.0)*5.0;
  float temperature = (voltage-0.5)*100; // 0.5 V represents 0 celsius degree.
  // every 10 mV change represents 1 celsius degree change, so 1 V represents 100 celsius change.
  lcd.setCursor(0,0);
  lcd.print("Temp          C ");
  lcd.setCursor(6, 0);
  lcd.print(temperature);
  delay(2000); // delay for 2 seconds
}
