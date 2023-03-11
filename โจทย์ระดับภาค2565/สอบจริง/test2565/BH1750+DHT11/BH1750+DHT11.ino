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
  tft.setRotation(2);
  tft.setTextSize(2);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawFastHLine(5, 100, 210, TFT_WHITE);
  tft.drawFastHLine(5, 200, 210, TFT_WHITE);
}

void loop() {
  int lux = (int)lightMeter.readLightLevel();
  int temp = dht.readTemperature();
  int humi = dht.readHumidity();
  tft.setTextSize(2);
  tft.drawString("Light Lux",0,0);
  tft.drawString("Humidity %",0,115);
  tft.drawString("Temperature C",0,220);
  tft.drawCircle(140, 220, 2, TFT_WHITE);
  tft.setTextSize(3);
  tft.drawString(String(lux),100,50);
  tft.drawString(String(humi), 100, 165);
  tft.drawString(String(temp), 100, 260);
};