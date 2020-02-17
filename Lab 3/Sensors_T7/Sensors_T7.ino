#include <IRremote.h>
#include <LiquidCrystal.h>
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int receiver = 5; // Signal Pin of IR receiver to Arduino Digital Pin 11
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'
void translateIR() // takes action based on IR code received
{
  switch (results.value) {
    case 0xFF629D: lcd.print("GO            "); break; // up arrow button
    case 0xFF22DD: lcd.print("LEFT          "); break; // left arrow button
    case 0xFF02FD: lcd.print("OK            "); break; // ok button
    case 0xFFC23D: lcd.print("RIGHT         "); break; // right arrow button
    case 0xFFA857: lcd.print("BACK          "); break; // down arrow button
    case 0xFF4AB5: lcd.print("0             "); break; // 0 button
    case 0xFF6897: lcd.print("1             "); break; // 1 button
    case 0xFF9867: lcd.print("2             "); break; // 2 button
    case 0xFFB04F: lcd.print("3             "); break; // 3 button
    case 0xFF30CF: lcd.print("4             "); break; // 4 button
    case 0xFF18E7: lcd.print("5             "); break; // 5 button
    case 0xFF7A85: lcd.print("6             "); break; // 6 button
    case 0xFF10EF: lcd.print("7             "); break; // 7 button
    case 0xFF38C7: lcd.print("8             "); break; // 8 button
    case 0xFF5AA5: lcd.print("9             "); break; // 9 button
    case 0xFF42BD: lcd.print("***           "); break; // star button
    case 0xFF52AD: lcd.print("###           "); break; // pound button
    case 0xFFFFFFFF: lcd.print("REPEAT      "); break; // any button pressed twice
    default:
      lcd.print("INVALID          ");
  }
  delay(800); // Do not get immediate repeat
} //END translateIR
void setup()
{
  lcd.begin(16, 2);
  irrecv.enableIRIn(); // Start the receiver
}
void loop()
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    lcd.setCursor(0, 0);
    lcd.print(results.value);
    lcd.setCursor(0, 1);
    translateIR();
    irrecv.resume(); // receive the next value
  }
}
