int cnt = 0;
#define swPin1 0
#define swPin2 1

void setup() {
  Serial.begin(115200);
  pinMode(swPin1, INPUT);
  pinMode(swPin2, INPUT);
}

void loop() {
  if (digitalRead(swPin1) == 0) {
    while (digitalRead(swPin1) == 0) delay(1);
    cnt++;
    Serial.println("cnt = " + String(cnt));
  }  //  if sw1 == 0
  else if (digitalRead(swPin2) == 0) {
    while (digitalRead(swPin2) == 0) delay(1);
    cnt--;
    if (cnt < 0) cnt = 0;
    Serial.println("cnt = " + String(cnt));
  }  //  if sw2 == 0
  while (cnt == 1) {
    if (digitalRead(swPin1) == 0) {
      while (digitalRead(swPin1) == 0) delay(1);
      cnt++;
      Serial.println("cnt = " + String(cnt));
    }  //  if sw1 == 0
    else if (digitalRead(swPin2) == 0) {
      while (digitalRead(swPin2) == 0) delay(1);
      cnt--;
      Serial.println("cnt = " + String(cnt));
    }  //  if sw2 == 0
    Serial.println("Loop While");
    delay(100);
  }
  Serial.println("Function Loop");
  delay(100);
}