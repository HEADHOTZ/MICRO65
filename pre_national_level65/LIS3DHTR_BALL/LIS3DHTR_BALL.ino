#include <TFT_eSPI.h>
#include <LIS3DHTR.h>
TFT_eSPI tft;
LIS3DHTR<TwoWire> lis;

int circle_x = 160;
int circle_y = 120;

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
  int x = ax * 100;
  int y = ay * 100;
  if (-10 < x && x < 10 && -10 < y && y < 10) {  //  Center
    if (circle_x >= 160) circle_x -= 10;
    if (circle_x <= 160) circle_x += 10;
    if (circle_y >= 120) circle_y -= 10;
    if (circle_y <= 120) circle_y += 10;
    Serial.println("Center");
  }
  if (x < -10 && -10 < y && y < 10) {  //  Top
    int val = map(x, -10, -100, 1, 100);
    tft.drawString("val : " + String(val) + String(" %"), 100, 100);
    circle_y -= val;
    Serial.println("Top");
  }
  if (x < -10 && y < -10) {  //  Top Right
    int val = map(y, -10, -80, 1, 100);
    tft.drawString("val : " + String(val) + String(" %"), 100, 100);
    circle_x += val;
    circle_y -= val;
    Serial.println("Top Right");
  }
  if (-10 < x && x < 10 && y < -10) {  //  Right
    int val = map(y, -10, -100, 1, 100);
    tft.drawString("val : " + String(val) + String(" %"), 100, 100);
    circle_x += val;
    Serial.println("Right");
  }
  if (x > 10 && y < -10) {  //  Bottom Right
    int val = map(y, -10, -80, 1, 100);
    tft.drawString("val : " + String(val) + String(" %"), 100, 100);
    circle_x += val;
    circle_y += val;
    Serial.println("Bottom Right");
  }
  if (x > 10 && -10 < y && y < 10) {  //  Bottom
    int val = map(x, 10, 100, 1, 100);
    tft.drawString("val : " + String(val) + String(" %"), 100, 100);
    circle_y += val;
    Serial.println("Bottom");
  }
  if (x > 10 && y > 10) {  //  Bottom Left
    int val = map(y, 10, 80, 1, 100);
    tft.drawString("val : " + String(val) + String(" %"), 100, 100);
    circle_x -= val;
    circle_y += val;
    Serial.println("Bottom Left");
  }
  if (-10 < x && x < 10 && y > 10) {  //  Left
    int val = map(y, 10, 100, 1, 100);
    tft.drawString("val : " + String(val) + String(" %"), 100, 100);
    circle_x -= val;
    Serial.println("Left");
  }
  if (x < -10 && y > 10) {
    int val = map(x, -10, -80, 1, 100);
    tft.drawString("val : " + String(val) + String(" %"), 100, 100);
    circle_x -= val;
    circle_y -= val;
    Serial.println("Top Left");
  }
  Serial.println("x = " + String(x));
  Serial.println("y = " + String(y));
  if (circle_x > 320) circle_x = 320;
  if (circle_x < 0) circle_x = 0;
  if (circle_y > 240) circle_y = 240;
  if (circle_y < 0) circle_y = 0;
  tft.fillScreen(TFT_BLACK);
  tft.fillCircle(circle_x, circle_y, 8, TFT_WHITE);
  delay(100);
}