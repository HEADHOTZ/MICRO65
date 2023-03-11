#define BLYNK_TEMPLATE_ID "TMPLKEd_SCq5"
#define BLYNK_DEVICE_NAME "BHT1750 DHT11"
#define BLYNK_AUTH_TOKEN "OA5--p7gLFLlZNoiFt7-4K9fDpTAm0ER"
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
char ssid[] = "home229/36";
char pass[] = "1234566495";
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
}

void loop() {
  Blynk.run();
  int lux = (int)lightMeter.readLightLevel();
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, humi);
  Blynk.virtualWrite(V2, lux);
  tft.setTextSize(3);
  tft.drawString("Temp", 50, 20);
  tft.setTextSize(2);
  tft.drawString(String(temp) + String(" C "), 40, 50);
  tft.drawCircle(105, 50, 3, TFT_WHITE);
  tft.drawString("Humi", 200, 20);
  tft.drawString(String(humi) + String(" %RH "), 200, 50);
  tft.drawString("light", 125, 200);
  tft.drawString(String(lux) + String(" lx "), 150, 150);
}