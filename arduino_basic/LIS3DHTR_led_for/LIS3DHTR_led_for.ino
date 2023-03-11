#include <TFT_eSPI.h>   // ผนวกไลบรารี ควบคุ มการแสดงผล LCD
#include <LIS3DHTR.h>   // ผนวกไลบรารี เชื่ อมต อและใช งานไอซี LIS3DHTR
TFT_eSPI tft;           // สร างออบเจ็ กต ชื่ อ tft จากคลาสTFT_eSPI สํ าหรั บควบคุ มการแสดงผล LCD
LIS3DHTR<TwoWire> lis;  // สร างออบเจ็ กต ชื่ อ lis สํ าหรั บใช งานไอซี ตรวจจั บความเร ง LIS3DHTR

int ledall[] = { BCM2, BCM3, BCM4, BCM5, BCM6, BCM7, BCM8, BCM9, BCM10, BCM11 };

int time = 50;
bool state_front = 0;
bool state_back = 0;
bool state_left = 0;
bool state_right = 0;

void setup() {
  for (int i = 0; i <= 10; i++) {
    pinMode(ledall[i], OUTPUT);
  }

  for (int i = 0; i <= 10; i++) {
    digitalWrite(ledall[i], 0);
  }

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
  float ax, ay, az;             // กํ าหนดตั วแปรเก็ บค าความเร งในแต ละแกน
  ax = lis.getAccelerationX();  // อ านค าความเร งแกน x
  ay = lis.getAccelerationY();  // อ านค าความเร งแกน y
  az = lis.getAccelerationZ();  // อ านค าความเร งแกน z
  int value = ay * 100;
  tft.setTextColor(TFT_WHITE, TFT_BLACK);                        // กํ าหนดสี ตั วอั กษรเป นสี ขาวพื้ นหลั งสี ดํ า
  tft.drawString("Ax : " + String(ax) + String(" "), 100, 80);   // แสดงค าความเร งแกน x ที่ จอแสดงผล LCD
  tft.drawString("Ay : " + String(ay) + String(" "), 100, 100);  // แสดงค าความเร งแกน y ที่ จอแสดงผล LCD
  tft.drawString("Az : " + String(az) + String(" "), 100, 120);  // แสดงค าความเร งแกน z ที่ จอแสดงผล LCD
  Serial.println("Ax = " + String(ax));
  Serial.println("Ay = " + String(ay));
  Serial.println("Az = " + String(az));
  if (ay > 0.1 /*&& az > -0.5 && az < 0.5*/) state_left = 1;  //  left
  else state_left = 0;
  if (az > 0.5 /*&& ay > -0.1 && ay < 0.1*/) state_back = 1;  //  back
  else state_back = 0;
  if (az < 0.5 /*&& ay > -0.1 && ay < 0.1*/) state_front = 1;  //  front
  else state_front = 0;
  if (ay < -0.1 /*&& az > -0.5 && az < 0.5*/) state_right = 1;  //  right
  else state_right = 0;
  if (state_left == 1) {
    for (int i = 10; i >= 0; i--) {
      ay = lis.getAccelerationY();
      if (ay < 0.10) continue;
      digitalWrite(ledall[i], 0);
      delay(map(value, 0, 100, 100, 10));
    }
    for (int i = 10; i >= 0; i--) {
      ay = lis.getAccelerationY();
      if (ay < 0.10) continue;
      digitalWrite(ledall[i], 1);
      delay(map(value, 0, 100, 100, 10));
    }
  }
  if (state_right == 1) {
    for (int i = 0; i <= 10; i++) {
      ay = lis.getAccelerationY();
      if (ay > 0.10) continue;
      digitalWrite(ledall[i], 0);
      delay(map(value, 0, -100, 100, 10));
    }
    for (int i = 0; i <= 10; i++) {
      ay = lis.getAccelerationY();
      if (ay > 0.90) continue;
      digitalWrite(ledall[i], 1);
      delay(map(value, 0, -100, 100, 10));
    }
  }
  if (state_front == 1) {
    for (int i = 0; i <= 10; i++) {
      digitalWrite(ledall[i], 1);
    }
  }
  if (state_back == 1) {
    for (int i = 0; i <= 10; i++) {
      digitalWrite(ledall[i], 0);
    }
  }
}
