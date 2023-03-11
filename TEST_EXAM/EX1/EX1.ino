#include <DHT.h>
#include <TFT_eSPI.h>
#include <Wire.h>
#include <math.h>
#define DHTPIN 2
#define DHTTYPE DHT11
TFT_eSPI tft;
DHT dht(DHTPIN, DHTTYPE);
int BH1750address = 0x23;
byte buff[2];

void setup() {
  Serial.begin(115200);
  dht.begin();
  Wire.begin();
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setTextSize(3);
}

void loop() {
  int i;
  uint16_t val = 0;
  BH1750_Init(BH1750address);
  //delay(200);
  if (2 == BH1750_Read(BH1750address))
  {
    val = ((buff[0] << 8) | buff[1]) / 1.2;
    Serial.print(val, DEC);
    Serial.println("lux");
  }
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  //if (isnan(h) || isnan(t) || isnan(f)) //isnan mean not-a-number num-give=1 notnum-give=0
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  //float hi = dht.computeHeatIndex(f, h);
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  tft.drawString("TEMP", 0, 0);
  tft.drawString("             ", 0, 30);
  tft.drawString(String(t), 0, 30);
  tft.drawString("HUMI", 200, 0);
  tft.drawString(String(h), 200, 30);
  tft.drawString("LIGHT", 100, 200);
  tft.drawString("            ", 125, 150);
  tft.drawString(String(val, DEC), 125, 150);
  delay(500);
}

int BH1750_Read(int address) //
{
  int i = 0;
  Wire.beginTransmission(address);
  Wire.requestFrom(address, 2);
  while (Wire.available()) //
  {
    buff[i] = Wire.read();  // receive one byte
    i++;
  }
  Wire.endTransmission();
  return i;
}

void BH1750_Init(int address)
{
  Wire.beginTransmission(address);
  Wire.write(0x10);//1lx reolution 120ms
  Wire.endTransmission();
}
