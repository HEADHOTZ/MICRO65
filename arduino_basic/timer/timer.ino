#define ledPin1 0
#define ledPin2 1
#define swPin 2
int timer = 0;
int timer1 = 0;
byte cnt = 0;
byte cnt1 = 0;
bool state = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(swPin, INPUT);
}

void loop() {
  if (!digitalRead(swPin)) {
    while (!digitalRead(swPin)) delay(10);
    cnt++;
    timer = 0;
    delay(1000);
  }
  if (timer == 20) {
    if (cnt == 1) {
      digitalWrite(ledPin1, 1);  // led1 ON
      Serial.println(" LED1 IS ON ");
      delay(1000);
    }
    if (cnt == 2) {
      digitalWrite(ledPin2, 1);  // led1 ON
      Serial.println(" LED2 IS ON ");
      state = 1;
      delay(1000);
    }
    while (state == 1) {
      if (!digitalRead(swPin)) {
        while (!digitalRead(swPin)) delay(10);
        cnt1++;
        timer1 = 0;
        delay(1000);
      }
      if (timer1 == 20) {
        if (cnt1 == 1) {
          digitalWrite(ledPin1, 0);
          Serial.println(" LED1 IS OFF ");
          delay(1000);
        }
        if (cnt1 == 2) {
          digitalWrite(ledPin2, 0);
          Serial.println(" LED2 IS OFF ");
          state = 0;
          delay(1000);
        }
        cnt1 = 0;
        timer1 = 0;
      }
      timer1++;
      Serial.println(timer1);
      Serial.println(cnt1);
      delay(100);
    }
    cnt = 0;
    timer = 0;
  }
  timer++;
  Serial.println(timer);
  Serial.println(cnt);
  delay(100);
}