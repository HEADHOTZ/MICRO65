#include <TFT_eSPI.h>
TFT_eSPI tft;

void setup() {
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_RED);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("20", 130, 120);
  tft.drawString("C", 170, 120);
  tft.drawCircle(160, 120, 3, TFT_BLACK);
}

void loop() {
}