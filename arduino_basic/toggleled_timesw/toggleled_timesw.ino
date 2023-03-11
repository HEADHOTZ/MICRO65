#define ledPin1 0
#define ledPin2 1
#define swPin 2
int timer = 0;
byte cnt = 0;
bool st1 = 0;
bool st2 = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(swPin, INPUT);
  digitalWrite(ledPin1, 0);
  digitalWrite(ledPin2, 0);
}

void loop() {
  if (!digitalRead(swPin)) {
    while (!digitalRead(swPin)) delay(10);
    cnt++;
    timer = 0;
    if (cnt > 2)
      cnt = 2;
  }  //  if sw == 0
  if (timer == 200) {
    if (cnt == 1) {
      //st1 = !st1;
      digitalWrite(ledPin1, !digitalRead(ledPin1));
      if (ledPin1 == 1) Serial.println("LED1 Is ON");
      else if (ledPin1 == 0) Serial.println("LED1 Is OFF");
      //Serial.println("LED1 Is Active");
      cnt = 0;
      timer = 0;
      delay(1000);
    }  //  if cnt == 1
    else if (cnt == 2) {
      //st2 = !st2;
      digitalWrite(ledPin2, !digitalRead(ledPin2));
      if (ledPin2 == 1) Serial.println("LED2 Is ON");
      else if (ledPin2 == 0) Serial.println("LED2 Is OFF");
      //Serial.println("LED2 Is Active");
      cnt = 0;
      timer = 0;
      delay(1000);
    }  //  if cnt == 1
    cnt = 0;
  }  //  if timer == 200
  timer++;
  Serial.println("cnt = " + String(cnt));
  delay(10);
};