float Vin = 3.3;
int R1 = 100;

void setup() {
  pinMode(A0, INPUT);
  analogReadResolution(12);
  Serial.begin(115200);
}

void loop() {
  int value = analogRead(A0);
  Serial.println("value = " + String(value));
  float volt = (value * 3.3) / 4096;
  if (volt > 0) {
    float ohm = (R1 * (Vin - volt)) / volt;
    Serial.println("R? = " + String(ohm));
  }
  delay(1000);
}
