#include <TFT_eSPI.h>
#include <DHT.h>
#define DHTPIN BCM0
#define DHTTYPE DHT11
TFT_eSPI tft;
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  dht.begin();
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_RED,TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("DHT11 Test", 80, 20);
  tft.drawString("DHT11 Test", 80, 20);
}

void loop() {
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  tft.drawString("Temp: "+String(temp)+String(" C "), 80, 100);
  tft.drawString("Humi: "+String(humi)+String(" %RH "), 80, 120);
  delay(1000);
}