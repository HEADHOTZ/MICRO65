#include <BH1750.h>
#include <Wire.h>
BH1750 lightMeter;
#define relay1 BCM4
#define relay2 BCM5
#define relay3 BCM6
#define relay4 BCM7
int timer = 0;
int cnt = 0;
bool st1 = 0;

void setup() {
  Wire.begin();
  lightMeter.begin();
  Serial.begin(115200);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
}

void loop() {
  int lux = (int)lightMeter.readLightLevel();
  while (lux < 5) {
    int lux = (int)lightMeter.readLightLevel();
    Serial.println("Light : " + String(lux));
    Serial.println("cnt : " + String(cnt));
    Serial.println("time : " + String(timer));
    if (lux > 5) {
      cnt++;
      timer = 0;
      break;
    }
    /*cnt++;
    timer = 0;
    delay(1000);*/
  }
  if (timer == 300) {
    if (cnt == 1) {
      digitalWrite(relay1, !digitalRead(relay1));
      cnt = 0;
      timer = 0;
      delay(1000);
    }  //  if cnt == 1
    else if (cnt == 2) {
      digitalWrite(relay2, !digitalRead(relay2));
      cnt = 0;
      timer = 0;
      delay(1000);
    }  //  if cnt == 2
    else if (cnt == 3) {
      digitalWrite(relay3, !digitalRead(relay3));
      cnt = 0;
      timer = 0;
      delay(1000);
    }  //  if cnt == 3
    else if (cnt == 4) {
      digitalWrite(relay4, !digitalRead(relay4));
      cnt = 0;
      timer = 0;
      delay(1000);
    }  //  if cnt == 4
    else if (cnt == 5) {
      st1 = !st1;
      digitalWrite(relay1, st1);
      digitalWrite(relay2, st1);
      digitalWrite(relay3, st1);
      digitalWrite(relay4, st1);
      cnt = 0;
      timer = 0;
      delay(1000);
    }
  }  //  if timer < 300
  Serial.println("Light : " + String(lux));
  Serial.println("cnt : " + String(cnt));
  Serial.println("time : " + String(timer));
  timer++;
  delay(10);
}