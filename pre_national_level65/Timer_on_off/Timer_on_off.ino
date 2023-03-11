#include <TFT_eSPI.h>
#include "RTC_SAMD51.h"
#include "DateTime.h"

TFT_eSPI tft;
RTC_SAMD51 rtc;
DateTime now;

#define SW1 BCM0
#define SW2 BCM1

byte timer;
byte mode;
byte cnt;

byte valh_in;
byte valm_in;
byte vals_in;

byte valh_out;
byte valm_out;
byte vals_out;

unsigned long previousMillis1 = 0;

void setup() {
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(A0, INPUT);

  tft.begin();
  tft.setRotation(3);
  tft.setTextSize(2);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  rtc.begin();
  now = DateTime(F(__DATE__), F(__TIME__));
  //rtc.adjust(now);

  tft.drawRoundRect(40, 10, 250, 50, 10, TFT_WHITE);
  tft.drawString("Timer ON-OFF", 70, 20);
  tft.drawString("TimerOn : 00.00.00", 40, 100);
  tft.drawString("TimerOff : 00.00.00", 40, 130);
}

void loop() {
  unsigned long currentMillis = millis();
  char i[20];
  now = rtc.now();
  int hour = now.hour();
  int min = now.minute();
  int sec = now.second();
  sprintf(i, "Time :%02d.%02d.%02d", hour, min, sec);
  tft.drawString(String(i) + String("   "), 40, 70);
  if (!digitalRead(SW1)) {
    timer++;
    Serial.println(timer);
    Serial.println(mode);
    delay(10);
    if (timer % 30 == 0) {
      mode += 1;
      if (mode > 2) mode = 0;
    }
  } else timer = 0;
  if (mode == 1) {
    if (!digitalRead(SW2)) {
      while (!digitalRead(SW2)) delay(10);
      cnt++;
      if (cnt > 2) cnt = 0;
    }
    if (cnt == 0) {
      valh_in = map(analogRead(A0), 2, 1023, 0, 24);
      if ((currentMillis - previousMillis1) >= 100) {
        sprintf(i, "TimerOn :   .%02d.%02d", valm_in, vals_in);
        tft.drawString(String(i) + String("   "), 40, 100);
        previousMillis1 = millis();  // save the "current" time
      }
      sprintf(i, "TimerOn : %02d.%02d.%02d", valh_in, valm_in, vals_in);
      tft.drawString(String(i) + String("   "), 40, 100);
    }  // if  cnt ==  0
    if (cnt == 1) {
      valm_in = map(analogRead(A0), 2, 1023, 0, 59);
      if ((currentMillis - previousMillis1) >= 100) {
        sprintf(i, "TimerOn : %02d.  .%02d", valh_in, vals_in);
        tft.drawString(String(i) + String("   "), 40, 100);
        previousMillis1 = millis();  // save the "current" time
      }
      sprintf(i, "TimerOn : %02d.%02d.%02d", valh_in, valm_in, vals_in);
      tft.drawString(String(i) + String("   "), 40, 100);
    }  // if  cnt ==  1
    if (cnt == 2) {
      vals_in = map(analogRead(A0), 2, 1023, 0, 59);
      if ((currentMillis - previousMillis1) >= 100) {
        sprintf(i, "TimerOn : %02d.%02d.  ", valh_in, valm_in);
        tft.drawString(String(i) + String("   "), 40, 100);
        previousMillis1 = millis();  // save the "current" time
      }
      sprintf(i, "TimerOn : %02d.%02d.%02d", valh_in, valm_in, vals_in);
      tft.drawString(String(i) + String("   "), 40, 100);
    }  // if  cnt ==  2
  }    // if  mode  ==  1
  if (mode == 2) {
    if (!digitalRead(SW2)) {
      while (!digitalRead(SW2)) delay(10);
      cnt++;
      if (cnt > 2) cnt = 0;
    }
    if (cnt == 0) {
      valh_out = map(analogRead(A0), 2, 1023, 0, 24);
      if ((currentMillis - previousMillis1) >= 100) {
        sprintf(i, "TimerOff :   .%02d.%02d", valm_out, vals_out);
        tft.drawString(String(i) + String("   "), 40, 130);
        previousMillis1 = millis();  // save the "current" time
      }
      sprintf(i, "TimerOff : %02d.%02d.%02d", valh_out, valm_out, vals_out);
      tft.drawString(String(i) + String("   "), 40, 130);
    }  // if  cnt ==  0
    if (cnt == 1) {
      valm_out = map(analogRead(A0), 2, 1023, 0, 59);
      if ((currentMillis - previousMillis1) >= 100) {
        sprintf(i, "TimerOff : %02d.  .%02d", valh_out, vals_out);
        tft.drawString(String(i) + String("   "), 40, 130);
        previousMillis1 = millis();  // save the "current" time
      }
      sprintf(i, "TimerOff : %02d.%02d.%02d", valh_out, valm_out, vals_out);
      tft.drawString(String(i) + String("   "), 40, 130);
    }  // if  cnt ==  1
    if (cnt == 2) {
      vals_out = map(analogRead(A0), 2, 1023, 0, 59);
      if ((currentMillis - previousMillis1) >= 100) {
        sprintf(i, "TimerOff : %02d.%02d.  ", valh_out, valm_out);
        tft.drawString(String(i) + String("   "), 40, 130);
        previousMillis1 = millis();  // save the "current" time
      }
      sprintf(i, "TimerOff : %02d.%02d.%02d", valh_out, valm_out, vals_out);
      tft.drawString(String(i) + String("   "), 40, 130);
    }  // if  cnt ==  2
  }    // if  mode  ==  2
}
