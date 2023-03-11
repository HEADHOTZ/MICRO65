#include <TFT_eSPI.h>
#include <LIS3DHTR.h>
TFT_eSPI tft;
LIS3DHTR<TwoWire> lis;
unsigned long last_time = 0;

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_WHITE);
  tft.setTextSize(2);
  lis.begin(Wire1);
  if (!lis) {
    tft.drawString("ERROR", 80, 120);
    while (1)
      ;
  }
  lis.setOutputDataRate(LIS3DHTR_DATARATE_25HZ);
  lis.setFullScaleRange(LIS3DHTR_RANGE_2G);
}

void loop() {
  float ax = lis.getAccelerationX();
  float ay = lis.getAccelerationY();
  float az = lis.getAccelerationZ();
  Serial.println("ay : " + String(ay));
  int value = ay * 100;
  int value_y = ax * 100;
  int value_z = az * 100;
  int map_x = map(value, 0, 100, 160, 0);
  int map_y = map(value_y, 0, 100, 120, 0);
  tft.drawCircle(map_x, map_y, 20, TFT_WHITE);
  tft.drawString(String(value) + String("    "), 100, 100);
  Serial.println("value : " + String(value));
  if (millis() - last_time > 100) {
    last_time = millis();
    tft.fillScreen(TFT_BLACK);
  }
}
