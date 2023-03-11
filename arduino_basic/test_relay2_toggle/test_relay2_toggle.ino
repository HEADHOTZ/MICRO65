#define sw1 BCM1
#define sw2 BCM2
#define sw3 BCM3
#define sw4 BCM4
#define relay1 BCM5
#define relay2 BCM6
#define relay3 BCM7
#define relay4 BCM8

void setup() {
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
}

void loop() {
  if (!digitalRead(sw1)) {
    while (!digitalRead(sw1)) delay(10);
    digitalWrite(relay1, !digitalRead(relay1));
    delay(200);
  }  //  if sw1 == 1
  if (!digitalRead(sw2)) {
    while (!digitalRead(sw2)) delay(10);
    digitalWrite(relay2, !digitalRead(relay2));
    delay(200);
  }  //  if sw2 == 1
  if (!digitalRead(sw3)) {
    while (!digitalRead(sw3)) delay(10);
    digitalWrite(relay3, !digitalRead(relay3));
    delay(200);
  }  //  if sw3 == 1
  if (!digitalRead(sw4)) {
    while (!digitalRead(sw4)) delay(10);
    digitalWrite(relay4, !digitalRead(relay4));
    delay(200);
  }  //  if sw4 == 1
}