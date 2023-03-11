#define BUZZER_PIN WIO_BUZZER /* sig pin of the buzzer */

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  //oneBeep();
  twoBeep();
}

void oneBeep() {
  analogWrite(WIO_BUZZER, 128);
  delay(100);
  analogWrite(WIO_BUZZER, 0);
  delay(500);
}

void twoBeep() {
  analogWrite(WIO_BUZZER, 128);
  delay(50);
  analogWrite(WIO_BUZZER, 0);
  delay(50);
  analogWrite(WIO_BUZZER, 128);
  delay(50);
  analogWrite(WIO_BUZZER, 0);
  delay(500);
}