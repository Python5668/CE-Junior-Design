int led_read = 3;
int led_write = 4;
int val = 0;

void setup() {
  pinMode(led_read, INPUT);
  pinMode(led_write, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(led_read);
  Serial.println(val);
  if (val == HIGH) {
    digitalWrite(led_write, HIGH);
    delay(250); // 1000 miliseconds divided by 4
    digitalWrite(led_write, LOW);
    delay(250);
  }
  while (val == LOW) {
    val = digitalRead(led_read);
    digitalWrite(led_write, HIGH);
    delay(1000);
    digitalWrite(led_write, LOW);
    delay(1000);
    }
}
