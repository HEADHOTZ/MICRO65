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
}

void loop() {
  int lux = (int)lightMeter.readLightLevel();
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  tft.setTextSize(3);
  tft.drawString("Temp", 50, 20);
  tft.setTextSize(2);
  tft.drawString(String(temp) + String(" C "),  40, 50);
  tft.drawCircle(105, 50, 3, TFT_WHITE);
  tft.drawString("Humi", 200, 20);
  tft.drawString(String(humi) + String(" %RH "), 200, 50);
  tft.drawString("light", 125, 200);
  tft.drawString(String(lux) + String(" lx "), 150, 150);
}