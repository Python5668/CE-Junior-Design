// Test 1: test the current ambient light + LED intensity
/*
void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);
}

void loop() {
  digitalWrite(3, 255);
  delay(1000);
  int a = analogRead(A0);
  Serial.println(a);
  Serial.end();
}
*/
// Just ambient light: 403
// ambient w/ LED: 705
// Middle point: 554

// Test 2: photocell sensing code w/ PID control and serial plot in arduino plotter
float kp = 0.1, ki = 0, kd = 0;
float error = 0, prevError = 0;
float P = 0, I = 0, D = 0;
float PID_val = 0;
int setpoint = 554;
float initialVal = 10;

void setup () {
  pinMode(3, OUTPUT);
  analogWrite(3, initialVal);
  Serial.begin(9600);
}

void loop() {
  int photoSignal = analogRead(A0);
  error = setpoint-photoSignal;
  P = error;
  I =+ error;
  D = error - prevError;
  prevError = error;
  
  PID_val = P*I*D;
  
  analogWrite(3, PID_val);
  Serial.print(setpoint);
  Serial.print(" ");
  Serial.println(photoSignal);
}
