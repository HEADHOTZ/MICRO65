#define vr1 A0

void setup() {
  pinMode(vr1, INPUT);
  analogReadResolution(12);
  Serial.begin(115200);
}

void loop() {
  int adc = analogRead(vr1);
  Serial.println(adc);
  delay(100);
}