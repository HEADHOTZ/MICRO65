#define LED1 BCM0
#define LED2 BCM1
#define sw1 BCM2

void setup() {
  Serial.println(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(sw1, INPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  attachInterrupt(digitalPinToInterrupt(sw1), Intcallback, FALLING);
}

void loop() {
  digitalWrite(LED1, HIGH);
  delay(2000);
  digitalWrite(LED1, LOW);
  delay(2000);
}

void Intcallback() {
  Serial.println("Interrupt OK!");
  digitalWrite(LED2, !digitalRead(LED2));
}