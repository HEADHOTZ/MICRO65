#include <TFT_eSPI.h>
#include "RTC_SAMD51.h"
#include "DateTime.h"
TFT_eSPI tft;
RTC_SAMD51 rtc;
DateTime now;

void setup() {
  rtc.begin();
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  now = DateTime(F(__DATE__), F(__TIME__));
  //rtc.adjust(now);  //  เมื่ออัปโหลดแล้วให้ comment บรรทัดนี้แล้วอัพอีกรอบ
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
  sprintf(s, "% 02d / % 02d / % d", day, month, year);
  tft.drawString(s, 100, 80);
  sprintf(s, "%02d:%02d:%02d", hour, min, sec);
  tft.drawString(s, 100, 100);
  delay(1000);
}