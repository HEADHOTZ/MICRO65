#include <TFT_eSPI.h>
#include <BH1750.h>
#include <DHT.h>
#include <Wire.h>
#define DHTPIN BCM0
#define DHTTYPE DHT11
TFT_eSPI tft;
BH1750 lightMeter;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Wire.begin();
  lightMeter.begin();
  dht.begin();
  tft.begin();
  tft.setRotation(3);
  tft.setTextSize(2);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawFastVLine(170, 120, 240, TFT_WHITE);
  tft.drawFastHLine(0, 120, 320, TFT_WHITE);
}

void loop() {
  int lux = (int)lightMeter.readLightLevel();
  int temp = dht.readTemperature();
  int humi = dht.readHumidity();
  tft.setTextSize(2);
  tft.drawString("light", 135, 10);
  tft.drawString("Temp", 70, 130);
  tft.drawString("Humid", 210, 130);
  tft.setTextSize(4);
  tft.drawString(String(lux) + String("    "), 125, 50);
  tft.drawString(String(temp), 75, 160);
  tft.drawString(String(humi), 215, 160);
  tft.drawCircle(135, 160, 3, TFT_WHITE);
}