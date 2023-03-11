efine BLYNK_TEMPLATE_ID "TMPLPwN-vlEe"
#define BLYNK_DEVICE_NAME "VR IoT"
#define BLYNK_FIRMWARE_VERSION "1.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"
#include <TFT_eSPI.h>

BlynkTimer timer;
TFT_eSPI tft;

#define LED1 BCM0
#define LED2 BCM1
#define LED3 BCM2

int val1;
int val2;
int val3;

bool mode;

void sendVR1() {
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  val1 = map(analogRead(A0), 2, 1023, 0, 100);
  tft.drawString(String(val1) + String(" %    "), 50, 50);
  Blynk.virtualWrite(V0, val1);
}

void sendVR2() {
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  val2 = map(analogRead(A1), 2, 1023, 0, 14);
  tft.drawString(String(val2) + String(" %    "), 50, 80);
  Blynk.virtualWrite(V1, val2);
}

void sendVR3() {
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  val3 = map(analogRead(A2), 2, 1023, 0, 1000);
  tft.drawString(String(val3) + String(" %    "), 50, 110);
  Blynk.virtualWrite(V2, val3);
}

void automatic() {
  if (mode == 1) {
    if (val1 > 60) digitalWrite(LED1, 1);
    else digitalWrite(LED1, 0);
    if (val2 > 6) digitalWrite(LED2, 1);
    else digitalWrite(LED2, 0);
    if (val3 > 100) digitalWrite(LED3, 1);
    else digitalWrite(LED3, 0);
  }
}

BLYNK_WRITE(V3) {
  mode = param.asInt();
}

BLYNK_WRITE(V4) {
  int val = param.asInt();
  if (mode == 0) {
    digitalWrite(LED1, val);
  }
}

BLYNK_WRITE(V5) {
  int val = param.asInt();
  if (mode == 0) {
    digitalWrite(LED2, val);
  }
}

BLYNK_WRITE(V6) {
  int val = param.asInt();
  if (mode == 0) {
    digitalWrite(LED3, val);
  }
}

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(3);
  BlynkEdgent.begin();
  timer.setInterval(0L, sendVR1);
  timer.setInterval(0L, sendVR2);
  timer.setInterval(0L, sendVR3);
  timer.setInterval(0L, automatic);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
  Serial.println(mode);
}