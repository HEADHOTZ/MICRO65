#include <Servo.h>
#include <TFT_eSPI.h>

TFT_eSPI tft;
Servo myservo;

byte cnt = 0;
byte wrong = 0;
int sec = 10;

int num1 = 0;
int num2 = 0;
int num3 = 0;
int num4 = 0;
int digit = 0;
int sum;

String text;

void setup() {
  myservo.attach(BCM9);
  myservo.write(0);

  pinMode(WIO_5S_UP, INPUT_PULLUP);
  pinMode(WIO_5S_DOWN, INPUT_PULLUP);
  pinMode(WIO_5S_LEFT, INPUT_PULLUP);
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);

  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("Password = 0000", 25, 40);
}

void loop() {
  Serial.println(sum);
  if (digit > 3) {
    if (sum == 2023) {
      wrong = 0;
      myservo.write(10);
    } else if (sum != 2023) {
      wrong += 1;
      myservo.write(90);
    }
    while (wrong == 4) {
      tft.fillScreen(TFT_BLACK);
      tft.setTextSize(4);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("LOCK", 100, 100);
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString(String(sec) + "    ", 175, 160);
      sec--;
      if (sec < 0) {
        tft.fillScreen(TFT_BLACK);
        sec = 10;
        wrong = 0;
      }
      delay(1000);
    }
    digit = 0;
    sum = 0;
    num1 = 0;
    num2 = 0;
    num3 = 0;
    num4 = 0;
    text = "";
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.drawString("Password = 0000", 25, 40);
  }
  if (!digitalRead(WIO_5S_PRESS)) {
    while (!digitalRead(WIO_5S_PRESS)) delay(10);
    if (cnt == 0) {
      tft.setTextSize(3);
      tft.drawString("^", 39, 190);
      if (digit == 0) num1 = 0 * 1000;
      else if (digit == 1) num2 = 0 * 100;
      else if (digit == 2) num3 = 0 * 10;
      else if (digit == 3) num4 = 0 * 1;
      text = text + "0";
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("Password = " + text, 25, 40);
    }
    if (cnt == 1) {
      tft.setTextSize(3);
      tft.drawString("^", 60, 190);
      if (digit == 0) num1 = 1 * 1000;
      else if (digit == 1) num2 = 1 * 100;
      else if (digit == 2) num3 = 1 * 10;
      else if (digit == 3) num4 = 1 * 1;
      text = text + "1";
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("Password = " + text, 25, 40);
    }
    if (cnt == 2) {
      tft.setTextSize(3);
      tft.drawString("^", 85, 190);
      if (digit == 0) num1 = 2 * 1000;
      else if (digit == 1) num2 = 2 * 100;
      else if (digit == 2) num3 = 2 * 10;
      else if (digit == 3) num4 = 2 * 1;
      text = text + "2";
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("Password = " + text, 25, 40);
    }
    if (cnt == 3) {
      tft.setTextSize(3);
      tft.drawString("^", 110, 190);
      if (digit == 0) num1 = 3 * 1000;
      else if (digit == 1) num2 = 3 * 100;
      else if (digit == 2) num3 = 3 * 10;
      else if (digit == 3) num4 = 3 * 1;
      text = text + "3";
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("Password = " + text, 25, 40);
    }
    if (cnt == 4) {
      tft.setTextSize(3);
      tft.drawString("^", 135, 190);
      if (digit == 0) num1 = 4 * 1000;
      else if (digit == 1) num2 = 4 * 100;
      else if (digit == 2) num3 = 4 * 10;
      else if (digit == 3) num4 = 4 * 1;
      text = text + "4";
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("Password = " + text, 25, 40);
    }
    if (cnt == 5) {
      tft.setTextSize(3);
      tft.drawString("^", 158, 190);
      if (digit == 0) num1 = 5 * 1000;
      else if (digit == 1) num2 = 5 * 100;
      else if (digit == 2) num3 = 5 * 10;
      else if (digit == 3) num4 = 5 * 1;
      text = text + "5";
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("Password = " + text, 25, 40);
    }
    if (cnt == 6) {
      tft.setTextSize(3);
      tft.drawString("^", 182, 190);
      if (digit == 0) num1 = 6 * 1000;
      else if (digit == 1) num2 = 6 * 100;
      else if (digit == 2) num3 = 6 * 10;
      else if (digit == 3) num4 = 6 * 1;
      text = text + "6";
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("Password = " + text, 25, 40);
    }
    if (cnt == 7) {
      tft.setTextSize(3);
      tft.drawString("^", 205, 190);
      if (digit == 0) num1 = 7 * 1000;
      else if (digit == 1) num2 = 7 * 100;
      else if (digit == 2) num3 = 7 * 10;
      else if (digit == 3) num4 = 7 * 1;
      text = text + "7";
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("Password = " + text, 25, 40);
    }
    if (cnt == 8) {
      tft.setTextSize(3);
      tft.drawString("^", 230, 190);
      if (digit == 0) num1 = 8 * 1000;
      else if (digit == 1) num2 = 8 * 100;
      else if (digit == 2) num3 = 8 * 10;
      else if (digit == 3) num4 = 8 * 1;
      text = text + "8";
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("Password = " + text, 25, 40);
    }
    if (cnt == 9) {
      tft.setTextSize(3);
      tft.drawString("^", 255, 190);
      if (digit == 0) num1 = 9 * 1000;
      else if (digit == 1) num2 = 9 * 100;
      else if (digit == 2) num3 = 9 * 10;
      else if (digit == 3) num4 = 9 * 1;
      text = text + "9";
      tft.setTextSize(2);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("Password = " + text, 25, 40);
    }
    digit += 1;
  }  //    if  WIO PRESS
  if (!digitalRead(WIO_5S_RIGHT)) {
    while (!digitalRead(WIO_5S_RIGHT)) delay(10);
    tft.fillScreen(TFT_BLACK);
    cnt++;
    if (cnt >= 9) cnt = 9;
  }
  if (!digitalRead(WIO_5S_LEFT)) {
    while (!digitalRead(WIO_5S_LEFT)) delay(10);
    tft.fillScreen(TFT_BLACK);
    cnt--;
    if (cnt == 255) cnt = 0;
  }
  if (cnt == 0) {
    tft.setTextSize(3);
    tft.drawString("^", 39, 190);
  }
  if (cnt == 1) {
    tft.setTextSize(3);
    tft.drawString("^", 60, 190);
  }
  if (cnt == 2) {
    tft.setTextSize(3);
    tft.drawString("^", 85, 190);
  }
  if (cnt == 3) {
    tft.setTextSize(3);
    tft.drawString("^", 110, 190);
  }
  if (cnt == 4) {
    tft.setTextSize(3);
    tft.drawString("^", 135, 190);
  }
  if (cnt == 5) {
    tft.setTextSize(3);
    tft.drawString("^", 158, 190);
  }
  if (cnt == 6) {
    tft.setTextSize(3);
    tft.drawString("^", 182, 190);
  }
  if (cnt == 7) {
    tft.setTextSize(3);
    tft.drawString("^", 205, 190);
  }
  if (cnt == 8) {
    tft.setTextSize(3);
    tft.drawString("^", 230, 190);
  }
  if (cnt == 9) {
    tft.setTextSize(3);
    tft.drawString("^", 255, 190);
  }
  sum = num1 + num2 + num3 + num4;
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("Password = " + text, 25, 40);
  tft.drawFastHLine(10, 120, 300, TFT_WHITE);
  tft.setTextSize(2);
  tft.drawString("0 1 2 3 4 5 6 7 8 9", 40, 160);
};
