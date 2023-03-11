void setup() {
  pinMode(BCM5, OUTPUT);
}

void loop() {
  digitalWrite(BCM5, LOW);
  delay(1000);
  digitalWrite(BCM5, HIGH);
  delay(1000);
}