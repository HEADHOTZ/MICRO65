#include <TFT_eSPI.h>   // ผนวกไลบรารี ควบคุ มการแสดงผล LCD
#include <LIS3DHTR.h>   // ผนวกไลบรารี เชื่ อมต อและใช งานไอซี LIS3DHTR
TFT_eSPI tft;           // สร างออบเจ็ กต ชื่ อ tft จากคลาสTFT_eSPI สํ าหรั บควบคุ มการแสดงผล LCD
LIS3DHTR<TwoWire> lis;  // สร างออบเจ็ กต ชื่ อ lis สํ าหรั บใช งานไอซี ตรวจจั บความเร ง LIS3DHTR

#define LED1 BCM2
#define LED2 BCM3
#define LED3 BCM4
#define LED4 BCM5
#define LED5 BCM6
#define LED6 BCM7
#define LED7 BCM8
#define LED8 BCM9
#define LED9 BCM10
#define LED10 BCM11

int time = 50;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);

  digitalWrite(LED1, 0);
  digitalWrite(LED2, 0);
  digitalWrite(LED3, 0);
  digitalWrite(LED4, 0);
  digitalWrite(LED5, 0);
  digitalWrite(LED6, 0);
  digitalWrite(LED7, 0);
  digitalWrite(LED8, 0);
  digitalWrite(LED9, 0);
  digitalWrite(LED10, 0);

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
  if (az >= 0.5) {  //  Back
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
    digitalWrite(LED4, 0);
    digitalWrite(LED5, 0);
    digitalWrite(LED6, 0);
    digitalWrite(LED7, 0);
    digitalWrite(LED8, 0);
    digitalWrite(LED9, 0);
    digitalWrite(LED10, 0);
  } else if (ay > 0.10) {
    digitalWrite(LED10, 0);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED9, 0);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED8, 0);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED7, 0);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED6, 0);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED5, 0);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED4, 0);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED3, 0);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED2, 0);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED1, 0);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED10, 1);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED9, 1);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED8, 1);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED7, 1);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED6, 1);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED5, 1);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED4, 1);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED3, 1);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED2, 1);
    delay(map(value, 0, -100, 100, 10));
    digitalWrite(LED1, 1);
    delay(map(value, 0, -100, 100, 10));
  } else if (ay > -0.90 && ay < 0.90) {
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 1);
    digitalWrite(LED3, 1);
    digitalWrite(LED4, 1);
    digitalWrite(LED5, 1);
    digitalWrite(LED6, 1);
    digitalWrite(LED7, 1);
    digitalWrite(LED8, 1);
    digitalWrite(LED9, 1);
    digitalWrite(LED10, 1);
  } else if (az > -0.5 && az < 0) {
    digitalWrite(LED1, 0);
    delay(time);
    digitalWrite(LED2, 0);
    delay(time);
    digitalWrite(LED3, 0);
    delay(time);
    digitalWrite(LED4, 0);
    delay(time);
    digitalWrite(LED5, 0);
    delay(time);
    digitalWrite(LED6, 0);
    delay(time);
    digitalWrite(LED7, 0);
    delay(time);
    digitalWrite(LED8, 0);
    delay(time);
    digitalWrite(LED9, 0);
    delay(time);
    digitalWrite(LED10, 0);
    delay(time);
    digitalWrite(LED1, 1);
    delay(time);
    digitalWrite(LED2, 1);
    delay(time);
    digitalWrite(LED3, 1);
    delay(time);
    digitalWrite(LED4, 1);
    delay(time);
    digitalWrite(LED5, 1);
    delay(time);
    digitalWrite(LED6, 1);
    delay(time);
    digitalWrite(LED7, 1);
    delay(time);
    digitalWrite(LED8, 1);
    delay(time);
    digitalWrite(LED9, 1);
    delay(time);
    digitalWrite(LED10, 1);
    delay(time);
  }
}