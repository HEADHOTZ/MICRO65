#include <DateTime.h>
#include <RTC_SAMD51.h>
#include <TFT_eSPI.h>
TFT_eSPI tft;
RTC_SAMD51 rtc;
DateTime now;
#define SW1 BCM0
#define SW2 BCM1
#define SW3 BCM2
#define SW4 BCM3
#define RY1 BCM4
#define RY2 BCM5
#define RY3 BCM6
#define RY4 BCM7
byte sw1_mode = 3;
byte sw2_mode = 3;
byte sw3_mode = 3;
byte sw4_mode = 3;
int sw1_time = 0;
int sw2_time = 0;
int sw3_time = 0;
int sw4_time = 0;

void setup() {
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
  pinMode(RY1, OUTPUT);
  pinMode(RY2, OUTPUT);
  pinMode(RY3, OUTPUT);
  pinMode(RY4, OUTPUT);
  rtc.begin();
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  now = DateTime(F(__DATE__), F(__TIME__));
  //rtc.adjust(now);
  attachInterrupt(digitalPinToInterrupt(SW1), sw1_callback, FALLING);
  attachInterrupt(digitalPinToInterrupt(SW2), sw2_callback, FALLING);
  attachInterrupt(digitalPinToInterrupt(SW3), sw3_callback, FALLING);
  attachInterrupt(digitalPinToInterrupt(SW4), sw4_callback, FALLING);
}

void loop() {
  char s[20];
  now = rtc.now();
  int day = now.day();
  int month = now.month();
  int year = now.year();
  int hour = now.hour();
  int min = now.minute();
  int sec = now.second();
  sprintf(s, "%02d/%02d/%d% 02d:%02d:%02d", day, month, year, hour, min, sec);
  tft.drawString(s, 50, 100);
  if (sw1_mode == 1 && sw1_time == now.second()) {  //  AUTO
    digitalWrite(RY1, !digitalRead(RY1));
    sw1_time = now.second() + 5;
    if (sw1_time >= 60) {
      sw1_time = sw1_time - 60;
    }
  } else if (sw1_mode == 2) digitalWrite(RY1, 1);  //  RYON
  else if (sw1_mode == 3) digitalWrite(RY1, 0);    //  RYOFF

  if (sw2_mode == 1 && sw2_time == now.second()) {  //  AUTO
    digitalWrite(RY2, !digitalRead(RY2));
    sw2_time = now.second() + 10;
    if (sw2_time >= 60) {
      sw2_time = sw2_time - 60;
    }
  } else if (sw2_mode == 2) digitalWrite(RY2, 1);  //  RYON
  else if (sw2_mode == 3) digitalWrite(RY2, 0);    //  RYOFF

  if (sw3_mode == 1 && sw3_time == now.second()) {  //  AUTO
    digitalWrite(RY3, !digitalRead(RY3));
    sw3_time = now.second() + 15;
    if (sw3_time >= 60) {
      sw3_time = sw3_time - 60;
    }
  } else if (sw3_mode == 2) digitalWrite(RY3, 1);  //  RYON
  else if (sw3_mode == 3) digitalWrite(RY3, 0);    //  RYOFF

  if (sw4_mode == 1 && sw4_time == now.second()) {  //  AUTO
    digitalWrite(RY4, !digitalRead(RY4));
    sw4_time = now.second() + 20;
    if (sw4_time >= 60) {
      sw4_time = sw4_time - 60;
    }
  } else if (sw4_mode == 2) digitalWrite(RY4, 1);  //  RYON
  else if (sw4_mode == 3) digitalWrite(RY4, 0);    //  RYOFF*/

  Serial.println("time1 : " + String(sw1_time));
  Serial.println("SW1 : " + String(sw1_mode));
  Serial.println("time2 : " + String(sw2_time));
  Serial.println("SW2 : " + String(sw2_mode));
  Serial.println("time3 : " + String(sw3_time));
  Serial.println("SW3 : " + String(sw3_mode));
  Serial.println("time4 : " + String(sw4_time));
  Serial.println("SW4 : " + String(sw4_mode));
  delay(1000);
}


void sw1_callback() {
  if (!digitalRead(SW1)) {
    while (!digitalRead(SW1)) delay(10);
    sw1_mode++;
    sw1_time = now.second() + 5;
    if (sw1_time >= 60) sw1_time = sw1_time - 60;
    if (sw1_mode > 3) sw1_mode = 1;
  }
}

void sw2_callback() {
  if (!digitalRead(SW2)) {
    while (!digitalRead(SW2)) delay(10);
    sw2_mode++;
    sw2_time = now.second() + 10;
    if (sw2_time >= 60) {
      sw2_time = sw2_time - 60;
    }
    if (sw2_mode > 3) sw2_mode = 1;
  }
}

void sw3_callback() {
  if (!digitalRead(SW3)) {
    while (!digitalRead(SW3)) delay(10);
    sw3_mode++;
    sw3_time = now.second() + 15;
    if (sw3_time >= 60) {
      sw3_time = sw3_time - 60;
    }
    if (sw3_mode > 3) sw3_mode = 1;
  }
}

void sw4_callback() {
  if (!digitalRead(SW4)) {
    while (!digitalRead(SW4)) delay(10);
    sw4_mode++;
    sw4_time = now.second() + 20;
    if (sw4_time >= 60) {
      sw4_time = sw4_time - 60;
    }
    if (sw4_mode > 3) sw4_mode = 1;
  }
}