#include <Servo.h>
#include <TFT_eSPI.h>
#define VR1 A0
#define VR2 A1
#define VR3 A2
#define VR4 A3
TFT_eSPI tft;
Servo myservo;
byte state = 0;
int num1 = 0;
int num2 = 0;
int num3 = 0;
int num4 = 0;
int password = 2565;
int sum;

void setup() {
  myservo.attach(BCM9);
  pinMode(VR1, INPUT);
  pinMode(VR2, INPUT);
  pinMode(VR3, INPUT);
  pinMode(VR4, INPUT);
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  myservo.write(90);
  myservo.write(0);
}

void loop() {
  int val_VR1 = map(analogRead(VR1), 2, 1023, 0, 9);
  int val_VR2 = map(analogRead(VR2), 2, 1023, 0, 9);
  int val_VR3 = map(analogRead(VR3), 2, 1023, 0, 9);
  int val_VR4 = map(analogRead(VR4), 2, 1023, 0, 9);
  if (!digitalRead(WIO_5S_PRESS)) {
    while (!digitalRead(WIO_5S_PRESS)) delay(10);
    state++;
    if (state > 4) {
      state = 0;
      sum = 0;
    }
    tft.fillScreen(TFT_BLACK);
    Serial.println("State : " + String(state));
  }
  if (state == 0) {
    tft.drawString("Key = " + String(val_VR1), 100, 150);
    Serial.println("NUM1 : " + String(num1));
  } else if (state == 1) {
    num1 = val_VR1 * 1000;
    tft.drawString("Key = " + String(val_VR2), 100, 150);
    Serial.println("NUM2 : " + String(num2));
  } else if (state == 2) {
    num2 = val_VR2 * 100;
    tft.drawString("Key = " + String(val_VR3), 100, 150);
    Serial.println("NUM3 : " + String(num3));
  } else if (state == 3) {
    num3 = val_VR3 * 10;
    tft.drawString("Key = " + String(val_VR4), 100, 150);
    Serial.println("NUM4 : " + String(num4));
  } else if (state == 4) {
    num4 = val_VR4;
    if (num1 + num2 + num3 + num4 == password) myservo.write(10);
    else if (num1 + num2 + num3 + num4 != password) myservo.write(90);
    num1 = 0;
    num2 = 0;
    num3 = 0;
    num4 = 0;
    state = 0;
    tft.fillScreen(TFT_BLACK);
  }
  tft.drawString("Password = " + String(num1 + num2 + num3 + num4), 75, 100);
  delay(100);
}