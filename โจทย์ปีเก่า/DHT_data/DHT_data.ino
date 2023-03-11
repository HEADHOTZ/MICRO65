#include <DHT.h>
#include <TFT_eSPI.h>
#include "RTC_SAMD51.h"
#include "DateTime.h"

#define DHTPIN BCM0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

RTC_SAMD51 rtc;
DateTime now;
TFT_eSPI tft;

void setup() {
  dht.begin();

  rtc.begin();
  now = DateTime(F(__DATE__), F(__TIME__));
  //rtc.adjust(now);

  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);

  Serial.begin(115200);
}

void loop() {
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  char s[20];
  now = rtc.now();
  int day = now.day();
  int month = now.month();
  int year = now.year();
  int hour = now.hour();
  int min = now.minute();
  int sec = now.second();
  sprintf(s, "DateTime: %02d-%02d-%2d :", year, month, day);
  tft.drawString(s, 0, 50);
  Serial.print(s);
  sprintf(s, " %02d:%02d:%02d", hour, min, sec);
  tft.drawString(s, 0, 100);
  Serial.print(s);
  sprintf(s, " Humid: %.2f %% Temp: %.2f C", humi, temp);
  tft.drawString(s, 0, 150);
  Serial.println(s);
  delay(1000);
}
