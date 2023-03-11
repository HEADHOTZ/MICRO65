#include <TFT_eSPI.h>
TFT_eSPI tft;

void setup() {
  pinMode(BCM27, OUTPUT);
  pinMode(BCM11, OUTPUT);
  pinMode(BCM1, OUTPUT);
  pinMode(BCM2, OUTPUT);
  pinMode(BCM3, OUTPUT);
  pinMode(BCM4, OUTPUT);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("DC MOTOR 2-CH", 80, 20);
  tft.drawString("Running...", 80, 40);
}

void loop() {
  digitalWrite(BCM1, 1);
  digitalWrite(BCM2, 0);
  analogWrite(BCM27, 127);

  digitalWrite(BCM3, 1);
  digitalWrite(BCM4, 0);
  analogWrite(BCM11, 127);
  delay(1000);

  digitalWrite(BCM1, 1);
  digitalWrite(BCM2, 1);
  analogWrite(BCM27, 0);

  digitalWrite(BCM3, 1);
  digitalWrite(BCM4, 1);
  analogWrite(BCM11, 0);
  delay(1000);

  digitalWrite(BCM1, 0);
  digitalWrite(BCM2, 1);
  analogWrite(BCM27, 255);

  digitalWrite(BCM3, 0);
  digitalWrite(BCM4, 1);
  analogWrite(BCM11, 255);
  delay(1000);

  digitalWrite(BCM1, 1);
  digitalWrite(BCM2, 1);
  analogWrite(BCM27, 0);

  digitalWrite(BCM3, 1);
  digitalWrite(BCM4, 1);
  analogWrite(BCM11, 0);
  delay(1000);
}