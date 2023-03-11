#define BLYNK_TEMPLATE_ID "TMPLPwN-vlEe"
#define BLYNK_DEVICE_NAME "VR IoT"
#define BLYNK_AUTH_TOKEN "r1BlWexW78pykSSGgVtPXptKt_wdjlxv"
#define BLYNK_PRINT Serial

#include <rpcWiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleWioTerminal.h>
#include <TFT_eSPI.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "yo";
char pass[] = "12345678";

BlynkTimer timer;
TFT_eSPI tft;

#define LED1 BCM0
#define LED2 BCM1
#define LED3 BCM2

int val1;
int val2;
int val3;
int cnt = 0;

bool mode;

void status() {
  /*bool isconnected = Blynk.connected();
  if (isconnected == false) Blynk.virtualWrite(V8, 0);
  else Blynk.virtualWrite(V8, 1);
  Blynk.virtualWrite(V9, digitalRead(LED1));
  Blynk.virtualWrite(V10, digitalRead(LED2));
  Blynk.virtualWrite(V11, digitalRead(LED3));*/
}

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
    if (val1 > 60) {
      digitalWrite(LED1, 1);
    } else digitalWrite(LED1, 0);
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

BLYNK_WRITE(V13) {
  int val = param.asInt();
  cnt = cnt - val;
  Blynk.virtualWrite(V12, cnt);
}

BLYNK_WRITE(V14) {
  int val = param.asInt();
  cnt = cnt + val;
  Blynk.virtualWrite(V12, cnt);
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

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(0L, sendVR1);
  timer.setInterval(0L, sendVR2);
  timer.setInterval(0L, sendVR3);
  timer.setInterval(0L, automatic);
  timer.setInterval(0L, status);
}

void loop() {
  Blynk.run();
  timer.run();
  bool isconnected = Blynk.connected();
  if (isconnected == false) Blynk.virtualWrite(V8, 0);
  if (cnt == 1) digitalWrite(LED1, 1);
  if (cnt == 2) digitalWrite(LED2, 1);
  if (cnt == 3) digitalWrite(LED3, 1);
  Blynk.virtualWrite(V9, digitalRead(LED1));
  Blynk.virtualWrite(V10, digitalRead(LED2));
  Blynk.virtualWrite(V11, digitalRead(LED3));
}