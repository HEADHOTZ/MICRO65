#define BLYNK_TEMPLATE_ID "TMPLi2OIPb-K"
#define BLYNK_DEVICE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "JWRgBQcrE1Nr3l9WQFp0FhONvm3-wAAq"
#define BLYNK_PRINT Serial
#define DHTPIN BCM0
#define DHTTYPE DHT11
#include <rpcWiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleWioTerminal.h>
#include <DHT.h>
#include <BH1750.h>
#include <Wire.h>
#include <TFT_eSPI.h>
BH1750 lightMeter;
TFT_eSPI tft;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "chaewon";
char pass[] = "1234567890";
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  Wire.begin();
  lightMeter.begin();
  tft.begin();
  tft.setRotation(3);
  tft.setTextSize(2);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("Temperature", 20, 30);
  tft.drawString("Humidity", 190, 30);
  tft.drawString("Light", 120, 210);
}

void loop() {
  Blynk.run();
  int lux = (int)lightMeter.readLightLevel();
  int temp = dht.readTemperature();
  int humi = dht.readHumidity();
  
  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, humi);
  Blynk.virtualWrite(V2, lux);

  tft.setRotation(3);  //ขาดไม่ได้ ใช้กำหนดฝั่ง
  tft.setTextSize(3);
  //tft.drawCircle(105, 65, 4, TFT_WHITE);  //กำหนดวงกลม
  tft.drawString(String(temp) /*+"C    "*/, 50, 70);
  tft.drawString(String(humi) /*+" % "*/, 210, 70);
  tft.drawString(String(lux) + "   " /*+" lx "*/, 130, 160);

  /*tft.setTextSize(3);
  tft.drawString("Temp", 50, 20);
  tft.setTextSize(2);
  tft.drawString(String(temp) + String(" C "), 40, 50);
  tft.drawCircle(105, 50, 3, TFT_WHITE);
  tft.drawString("Humi", 200, 20);
  tft.drawString(String(humi) + String(" %RH "), 200, 50);
  tft.drawString("light", 125, 200);
  tft.drawString(String(lux) + String(" lx "), 150, 150);*/
};