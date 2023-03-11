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
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;
unsigned long previousMillis5 = 0;

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
}

void loop() {
  unsigned long currentMillis = millis();
  if ((currentMillis - previousMillis1) >= 1000) {
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
    previousMillis1 = millis();  // save the "current" time
  }
  if (!digitalRead(SW1)) {
    while (!digitalRead(SW1)) delay(10);
    sw1_mode++;
    if (sw1_mode > 3) sw1_mode = 1;
  }
  if (!digitalRead(SW2)) {
    while (!digitalRead(SW2)) delay(10);
    sw2_mode++;
    if (sw2_mode > 3) sw2_mode = 1;
  }
  if (!digitalRead(SW3)) {
    while (!digitalRead(SW3)) delay(10);
    sw3_mode++;
    if (sw3_mode > 3) sw3_mode = 1;
  }
  if (!digitalRead(SW4)) {
    while (!digitalRead(SW4)) delay(10);
    sw4_mode++;
    if (sw4_mode > 3) sw4_mode = 1;
  }
  if (sw1_mode == 1) {  //AUTO RY1
    if ((currentMillis - previousMillis2) >= 5000) {
      digitalWrite(RY1, !digitalRead(RY1));
      previousMillis2 = millis();  // save the "current" time
    }
  } else if (sw1_mode == 2) digitalWrite(RY1, 1);  //  RY1 ON
  else if (sw1_mode == 3) digitalWrite(RY1, 0);    //  RY2 OFF
  if (sw2_mode == 1) {                             //AUTO RY1
    if ((currentMillis - previousMillis3) >= 10000) {
      digitalWrite(RY2, !digitalRead(RY2));
      previousMillis3 = millis();  // save the "current" time
    }
  } else if (sw2_mode == 2) digitalWrite(RY2, 1);  //  RY1 ON
  else if (sw2_mode == 3) digitalWrite(RY2, 0);    //  RY2 OFF
  if (sw3_mode == 1) {                             //AUTO RY1
    if ((currentMillis - previousMillis4) >= 15000) {
      digitalWrite(RY3, !digitalRead(RY3));
      previousMillis4 = millis();  // save the "current" time
    }
  } else if (sw3_mode == 2) digitalWrite(RY3, 1);  //  RY1 ON
  else if (sw3_mode == 3) digitalWrite(RY3, 0);    //  RY2 OFF
  if (sw4_mode == 1) {                             //AUTO RY1
    if ((currentMillis - previousMillis5) >= 20000) {
      digitalWrite(RY4, !digitalRead(RY4));
      previousMillis5 = millis();  // save the "current" time
    }
  } else if (sw4_mode == 2) digitalWrite(RY4, 1);  //  RY1 ON
  else if (sw4_mode == 3) digitalWrite(RY4, 0);    //  RY2 OFF
};