#define swPin1 0
#define swPin2 1
int cnt = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin1, INPUT);
  pinMode(swPin2, INPUT);
}

void loop() {
  if (digitalRead(swPin1) == 0) {
    while (digitalRead(swPin1) == 0) delay(1);
    cnt = cnt + 1;
    Serial.println("cnt = " + String(cnt));
  }  //  if sw1 == 0
  else if (digitalRead(swPin2) == 0) {
    while (digitalRead(swPin2) == 0) delay(1);
    cnt = cnt - 1;
    if (cnt < 0) cnt = 0;
    Serial.println("cnt = " + String(cnt));
  }  //  if sw2 == 0
  switch (cnt) {
    case 1:
      Serial.println("case1");
      break;
    case 2:
      Serial.println("case2");
      break;
    default:
      Serial.println("default");
      break;
  }
  delay(100);
}