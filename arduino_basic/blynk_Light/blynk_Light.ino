#define BLYNK_TEMPLATE_ID "TMPLPwN-vlEe"
#define BLYNK_DEVICE_NAME "VR IoT"
#define BLYNK_FIRMWARE_VERSION "0.1.0"  // สํ าหรั บกํ าหนดค ารหั ส FIRMWARE VERSION
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"  // ผนวกไลบรารี สํ าหรั บติ ดต อ Blynk IoT
#include <TFT_eSPI.h>

TFT_eSPI tft;      // สร างออปเจ็ กต ชื่ อ tft จากคลาส TFT_eSPI สํ าหรั บควบคุ มการแสดงผล LCD
BlynkTimer timer;  // สร างออปเจ็ กต BlynkTimer ชื่ อ timer
void sendLight()   // ฟ งก ชั่ นสํ าหรั บทํ าหน าที่ แสดงผลค าระดั บแสงและส งไปแสดงผลที่ Blynk IoT App
{
  int light = analogRead(WIO_LIGHT);           // อ านค าความเข มของแสงจากตั วตรวจจั บแสง
  String str = "Light: " + String(light);      // แปลงค าระดั บแสงเป นข อมู ลสตริ ง
  tft.drawString(str + String(" "), 80, 120);  // แสดงค าระดั บแสง
  Blynk.virtualWrite(V0, light);               // ส งค าระดั บแสงไปแสดงผลที่ Blynk App ผ านช อง V0
}
void setup() {
  Serial.begin(115200);                     // ใช Serial Monitor แจ งสถานะการเชื่ อมต อเซิ ร ฟเวอร Blynk
  delay(100);                               // หน วงเวลาเล็ กน อย
  pinMode(WIO_LIGHT, INPUT);                // กํ าหนดขาพอร ตที่ เชื่ อมต อกั บตั วตรวจจั บแสงให เป นอิ นพุ ต
  tft.begin();                              // เริ่ มต นการทํ างานของจอแสดงผล
  tft.setRotation(3);                       // กํ าหนดทิ ศทางการหมุ นหน าจอแสดงผล
  tft.fillScreen(TFT_BLACK);                // ระบายสี ดํ าเป นพื้ นหลั งหน าจอ LCD
  tft.setTextColor(TFT_ORANGE, TFT_BLACK);  // กํ าหนดสี ตั วอั กษรเป นสี เขี ยว พื้ นหลั งสี ดํ า
  tft.setTextSize(3);                       // กํ าหนดขนาดฟอนต เป น 3
  tft.drawString("Wait...", 80, 120);       // แสดงข อความ Wait...
  BlynkEdgent.begin();                      // เริ่ มต นเชื่ อมต อไปยั งเซิ ร ฟเวอร Blynk IoT
  timer.setInterval(1000L, sendLight);      // เป ดใช งานไทเมอร อิ นเตอร รั ปต ทุ กๆ 1 วิ นาที
}  // กํ าหนดให ไปทํ างานที่ ฟ งก ชั่ น sendLight
void loop() {
  BlynkEdgent.run();  // สั่ งรั น Blynk IoT
  timer.run();        // สั่ งรั นไทเมอร
}