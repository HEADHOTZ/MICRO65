#include <TFT_eSPI.h>
#include <BH1750.h>
#include <Wire.h>
#define RY1 BCM0
BH1750 lightMeter;
TFT_eSPI tft;
int max_value = 70;
int min_value = 30;
bool state_max = 0;
bool state_min = 0;
unsigned long previousMillis1 = 0;

void setup() {
  pinMode(WIO_5S_UP, INPUT_PULLUP);
  pinMode(WIO_5S_DOWN, INPUT_PULLUP);
  pinMode(WIO_5S_LEFT, INPUT_PULLUP);
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);
  pinMode(RY1, OUTPUT);
  Wire.begin();
  lightMeter.begin();
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
}

void loop() {
  unsigned long currentMillis = millis();
  int lux = (int)lightMeter.readLightLevel();
  int val = map(lux, 0, 218, 0, 100);
  if ((currentMillis - previousMillis1) >= 200) {
    tft.drawString(String("                      "), 40, 10);
    previousMillis1 = millis();  // save the "current" time
  }
  if (val <= min_value) digitalWrite(RY1, 1);
  else if (val >= max_value) digitalWrite(RY1, 0);
  if (digitalRead(WIO_5S_UP) == LOW) {
    tft.fillScreen(TFT_BLACK);
    state_max = 1;
    state_min = 0;
    tft.drawString(">", 30, 60);
  } else if (digitalRead(WIO_5S_DOWN) == LOW) {
    tft.fillScreen(TFT_BLACK);
    state_max = 0;
    state_min = 1;
    tft.drawString(">", 30, 110);
  } else if (digitalRead(WIO_5S_RIGHT) == LOW) {
    if (state_max == 1) {
      tft.fillScreen(TFT_BLACK);
      tft.drawString(">", 30, 60);
      max_value++;
      if (max_value > 100) max_value = 100;
    } else if (state_min == 1) {
      tft.fillScreen(TFT_BLACK);
      tft.drawString(">", 30, 110);
      min_value++;
      if (min_value > 100) min_value = 100;
    }
  } else if (digitalRead(WIO_5S_LEFT) == LOW) {
    if (state_max == 1) {
      tft.fillScreen(TFT_BLACK);
      tft.drawString(">", 30, 60);
      max_value--;
      if (max_value < 0) max_value = 0;
    } else if (state_min == 1) {
      tft.fillScreen(TFT_BLACK);
      tft.drawString(">", 30, 110);
      min_value--;
      if (min_value < 0) min_value = 0;
    }
  }
  tft.setTextSize(4);
  tft.drawString(String("LUMI = ") + String(val) + String(" %"), 40, 10);
  tft.setTextSize(3);
  tft.drawString(String("MAX = ") + String(max_value) + String(" %"), 50, 60);
  tft.drawString(String("MIN = ") + String(min_value) + String(" %"), 50, 110);
};