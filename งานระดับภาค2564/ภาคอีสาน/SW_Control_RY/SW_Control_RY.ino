#include <TFT_eSPI.h>
#define SW1 BCM0
#define SW2 BCM1
#define SW3 BCM2
#define SW4 BCM3
#define SWON BCM4
#define SWOFF BCM5
#define RY1 BCM6
#define RY2 BCM7
#define RY3 BCM8
#define RY4 BCM9
TFT_eSPI tft;

void setup() {
  tft.begin();
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(4);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
  pinMode(SWON, INPUT);
  pinMode(SWOFF, INPUT);
  pinMode(RY1, OUTPUT);
  pinMode(RY2, OUTPUT);
  pinMode(RY3, OUTPUT);
  pinMode(RY4, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (!digitalRead(SW1)) {
    while (!digitalRead(SW1)) delay(10);
    digitalWrite(RY1, !digitalRead(RY1));
    tft.fillScreen(TFT_BLACK);
  }
  if (!digitalRead(SW2)) {
    while (!digitalRead(SW2)) delay(10);
    digitalWrite(RY2, !digitalRead(RY2));
    tft.fillScreen(TFT_BLACK);
  }
  if (!digitalRead(SW3)) {
    while (!digitalRead(SW3)) delay(10);
    digitalWrite(RY3, !digitalRead(RY3));
    tft.fillScreen(TFT_BLACK);
  }
  if (!digitalRead(SW4)) {
    while (!digitalRead(SW4)) delay(10);
    digitalWrite(RY4, !digitalRead(RY4));
    tft.fillScreen(TFT_BLACK);
  }
  if (!digitalRead(SWON)) {
    while (!digitalRead(SWON)) delay(10);
    digitalWrite(RY1, 1);
    digitalWrite(RY2, 1);
    digitalWrite(RY3, 1);
    digitalWrite(RY4, 1);
    tft.fillScreen(TFT_BLACK);
  }
  if (!digitalRead(SWOFF)) {
    while (!digitalRead(SWOFF)) delay(10);
    digitalWrite(RY1, 0);
    digitalWrite(RY2, 0);
    digitalWrite(RY3, 0);
    digitalWrite(RY4, 0);
    tft.fillScreen(TFT_BLACK);
  }
  tft.drawString("RY1 : " + String(digitalRead(RY1)), 0, 10);
  tft.drawString("RY2 : " + String(digitalRead(RY2)), 0, 60);
  tft.drawString("RY3 : " + String(digitalRead(RY3)), 0, 110);
  tft.drawString("RY4 : " + String(digitalRead(RY4)), 0, 160);
}