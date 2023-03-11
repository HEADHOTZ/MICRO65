#include <TFT_eSPI.h>
#include "RTC_SAMD51.h"
#include "DateTime.h"
#include <BH1750.h>
#include <Wire.h>

BH1750 lightMeter;
TFT_eSPI tft;
RTC_SAMD51 rtc;
DateTime now;

byte mode = 0;
bool state = 0;

unsigned long previousMillis1 = 0;

#define RY1 BCM4

void setup() {
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);
  pinMode(RY1, OUTPUT);

  Wire.begin();
  lightMeter.begin();

  rtc.begin();
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  now = DateTime(F(__DATE__), F(__TIME__));
  rtc.adjust(now);
}

void loop() {
  //rtc.adjust(now);
  int lux = (int)lightMeter.readLightLevel();
  int val = map(lux, 0, 500, 0, 200);
  tft.fillRoundRect(50, 180, 200, 30, 1, TFT_WHITE);
  tft.fillRoundRect(50, 180, val - 10, 30, 1, TFT_GREEN);

  char s[20];
  now = rtc.now();
  int day = now.day();
  int month = now.month();
  int year = now.year();
  int hour = now.hour();
  int min = now.minute();
  int sec = now.second();
  tft.setTextSize(2);
  sprintf(s, "%02d/%02d/%d", day, month, year);
  tft.drawString(s, 120, 20);
  sprintf(s, "%02d:%02d:%02d", hour, min, sec);
  tft.drawString(s, 130, 50);
  if (!digitalRead(WIO_5S_PRESS)) {
    while (!digitalRead(WIO_5S_PRESS)) delay(10);
    tft.fillScreen(TFT_BLACK);
    mode += 1;
    if (mode > 3) mode = 0;
  }
  if (mode == 0) {
    unsigned long currentMillis = millis();
    tft.setTextSize(3);
    tft.drawString("Auto Time", 80, 100);
    if (sec - previousMillis1 >= 10) {
      digitalWrite(RY1, !digitalRead(RY1));
      previousMillis1 = sec;
    }
  }
  if (mode == 1) {
    tft.setTextSize(3);
    tft.drawString("Auto Sensor", 80, 100);
    if (val > 5) digitalWrite(RY1, 0);
    if (val < 5) digitalWrite(RY1, 1);
  }
  if (mode == 2) {
    tft.setTextSize(3);
    tft.drawString("ON", 140, 100);
    digitalWrite(RY1, 1);
  }
  if (mode == 3) {
    tft.setTextSize(3);
    tft.drawString("OFF", 140, 100);
    digitalWrite(RY1, 0);
  }
  Serial.println(val);
}