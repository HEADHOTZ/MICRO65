int cnt = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (cnt == 10) Serial.println("cnt=" + String(cnt));
  else cnt++;
  delay(100);
};