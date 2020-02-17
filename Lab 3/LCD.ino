#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int t = 200; // delay in milliseconds

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  // shift "Durango" to the right
  for (int i = 0; i <= 4; i++) {
    lcd.setCursor(i, 1);
    lcd.print("Durango");
    delay(t);
    if (i < 4) {
      lcd.clear();
    }
  }
  // make "Durango" blink on and off
  for (int j = 0; j <= 2; j++ ) {
    lcd.setCursor(4, 1);
    delay(t*3);
    lcd.print("Durango");
    delay(t*3);
    lcd.clear();
  }
  // shift "Durango" to the right off screen
  for (int i = 4; i <= 16; i++) {
    lcd.setCursor(i, 1);
    lcd.print("Durango");
    delay(t);
    if (i < 16) {lcd.clear();}
  }
}
