#include <TFT_eSPI.h>
#include <LIS3DHTR.h>
#include <Adafruit_NeoPixel.h>
TFT_eSPI tft;
LIS3DHTR<TwoWire> lis;

#define PIN BCM27
#define NUMPIXELS 12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

bool state_front = 0;
bool state_back = 0;
bool state_left = 0;
bool state_right = 0;

void setup() {
  pixels.begin();
  pixels.setBrightness(10);
  pixels.show();
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_WHITE);
  tft.setTextSize(2);  // กํ าหนดขนาดฟอนต เป น 2
  lis.begin(Wire1);    // เริ่ มต นการติ ดต อกั บไอซี LIS3DHTR
  if (!lis)            // ตรวจสอบการเชื่ อมต อกั บตั วตรวจจั บความเร ง
  {
    tft.drawString("ERROR", 80, 120);
    while (1)
      ;
  }

  lis.setOutputDataRate(LIS3DHTR_DATARATE_25HZ);
  lis.setFullScaleRange(LIS3DHTR_RANGE_2G);
}

void loop() {
  float ax, ay, az;                                              // กํ าหนดตั วแปรเก็ บค าความเร งในแต ละแกน
  ax = lis.getAccelerationX();                                   // อ านค าความเร งแกน x
  ay = lis.getAccelerationY();                                   // อ านค าความเร งแกน y
  az = lis.getAccelerationZ();                                   // อ านค าความเร งแกน z
  tft.setTextColor(TFT_WHITE, TFT_BLACK);                        // กํ าหนดสี ตั วอั กษรเป นสี ขาวพื้ นหลั งสี ดํ า
  tft.drawString("Ax : " + String(ax) + String(" "), 100, 80);   // แสดงค าความเร งแกน x ที่ จอแสดงผล LCD
  tft.drawString("Ay : " + String(ay) + String(" "), 100, 100);  // แสดงค าความเร งแกน y ที่ จอแสดงผล LCD
  tft.drawString("Az : " + String(az) + String(" "), 100, 120);  // แสดงค าความเร งแกน z ที่ จอแสดงผล LCD
  Serial.println("Ax = " + String(ax));
  Serial.println("Ay = " + String(ay));
  Serial.println("Az = " + String(az));
  if (ay > 0.5 /*&& az > -0.5 && az < 0.5*/) state_left = 1;  //  left
  else state_left = 0;
  if (az > 0.5 /*&& ay > -0.9 && ay < 0.9*/) state_back = 1;  //  back
  else state_back = 0;
  if (az < 0.5 /*&& ay > -0.9 && ay < 0.9*/) state_front = 1;  //  front
  else state_front = 0;
  if (ay < -0.5 /*&& az > -0.5 && az < 0.5*/) state_right = 1;  //  right
  else state_right = 0;
  if (state_left == 1) {
    for (int i = NUMPIXELS; i >= 0; i--) {
      ay = lis.getAccelerationY();
      if (ay < 0.90) continue;
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();
      delay(50);
    }
    for (int i = NUMPIXELS; i >= 0; i--) {
      ay = lis.getAccelerationY();
      if (ay < 0.90) continue;
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));
      pixels.show();
      delay(50);
    }
  }
  if (state_right == 1) {
    for (int i = 0; i <= NUMPIXELS; i++) {
      ay = lis.getAccelerationY();
      if (ay > 0.90) continue;
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();
      delay(50);
    }
    for (int i = 0; i <= NUMPIXELS; i++) {
      ay = lis.getAccelerationY();
      if (ay > 0.90) continue;
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));
      pixels.show();
      delay(50);
    }
  }
  if (state_front == 1) {
    for (int i = 0; i <= NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));
      pixels.show();
    }
  }
  if (state_back == 1) {
    for (int i = 0; i <= NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();
    }
  }
}
