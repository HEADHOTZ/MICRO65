#include <TFT_eSPI.h>           // ผนวกไลบรารี ควบคุ มการแสดงผล LCD
#include <RTC_SAMD51.h>         // ผนวกไลบรารี การติ ดต อกั บ RTC
#include <DateTime.h>           // ผนวกไลบรารี สํ าหรั บจั ดการเกี่ ยวกั บข อมู ลวั นที่ และเวลา
TFT_eSPI tft;                   // สร างออบเจ็ กต ชื่ อ tft จากคลาส TFT_eSPI สํ าหรั บควบคุ มการแสดงผล
RTC_SAMD51 rtc;                 // กํ าหนดตั วแปรจั ดการเชื่ อมต อกั บ RTC
DateTime now;                   // กํ าหนดตั วแปรจั ดการเกี่ ยวกั บข อมู ลวั นที่ และเวลา
void alarmMatch(uint32_t flag)  // ฟ งก ชั่ นตอบสนองอิ นเตอร รั ปต เมื่ อถึ งเวลาที่ ตั้ งไว
{
  tft.fillScreen(TFT_BLACK);                 // ล างจอแสดงผลด วยการกํ าหนดให พื้ นหลั งแสดงเป นสี ดํ า
  tft.drawString("Alarm Match !", 100, 80);  // แสดงข อความแจ งเตื อนเมื่ อถึ งเวลาที่ ตั้ งไว
  while (1)
    ;  // หยุ ดการทํ างานของโปรแกรมไว ที่ ตํ าแหน งนี้
}
void setup() {
  rtc.begin();                               // เริ่ มต นการทํ างานของ RTC
  tft.begin();                               // เริ่ มต นการทํ างานของ LCD
  tft.setRotation(3);                        // กํ าหนดทิ ศทางการแสดงผลของ LCD
  tft.fillScreen(TFT_BLACK);                 // ล างจอแสดงผลด วยการกํ าหนดให พื้ นหลั งแสดงเป นสี ดํ า
  tft.setTextColor(TFT_WHITE, TFT_BLACK);    // กํ าหนดสี ตั วอั กษรเป นสี ขาวพื้ นหลั งสี ดํ า
  tft.setTextSize(2);                        // กํ าหนดขนาดฟอนต เป น 2
  now = DateTime(F(__DATE__), F(__TIME__));  // กํ าหนดรู ปแบบเก็ บข อมู ลวั นที่ และเวลา
  rtc.adjust(now);                           // ปรั บค าเวลาเป นป จจุ บั น
  DateTime alarm = DateTime(now.year(),
                            now.month(),
                            now.day(),
                            now.hour(),
                            now.minute(),
                            now.second() + 15);
  rtc.setAlarm(0, alarm);
  rtc.enableAlarm(0, rtc.MATCH_HHMMSS);
  rtc.attachInterrupt(alarmMatch);
}
void loop() {
  char s[20];
  now = rtc.now();
  int day = now.day();
  int month = now.month();
  int year = now.year();                         // อ านค าป
  int hour = now.hour();                         // อ านค าชั่ วโมง
  int min = now.minute();                        // อ านค านาที
  int sec = now.second();                        // อ านค าวิ นาที
  sprintf(s, "%02d/%02d/%d", day, month, year);  // แปลงรู ปแบบข อมู ลเป นวั นที่ เดื อน ป เก็ บไว ที่ ตั วแปร s
  tft.drawString(s, 100, 80);                    // แสดงวั นที่
  sprintf(s, "%02d:%02d:%02d", hour, min, sec);
  tft.drawString(s, 100, 100);
  delay(1000);
}