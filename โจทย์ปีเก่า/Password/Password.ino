#include "TFT_eSPI.h"
#include <Adafruit_NeoPixel.h>
#define PIN BCM27
#define NUMPIXELS 12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
TFT_eSPI tft;

#define SW1 BCM0
#define SW2 BCM1
#define SW3 BCM2
#define SW4 BCM3
#define SW5 BCM4
#define SW6 BCM5
#define SW7 BCM6
#define SW8 BCM7

int num1 = 0;
int num2 = 0;
int num3 = 0;
int num4 = 0;
int digit = 0;
int sum;
String text;

void setup() {
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(3);
  tft.drawString("0000", 100, 100);

  pixels.begin();
  pixels.setBrightness(10);
  pixels.show();

  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
  pinMode(SW5, INPUT);
  pinMode(SW6, INPUT);
  pinMode(SW7, INPUT);
  pinMode(SW8, INPUT);
}

void loop() {
  if (digit > 3) {
    if (sum == 2047) {
      tft.fillScreen(TFT_BLACK);
      tft.drawString("Ant Man", 100, 50);
      pixels.setPixelColor(0, pixels.Color(0, 255, 0));
      pixels.show();
      delay(1000);
      tft.drawString("0000", 100, 100);
    } else if (sum == 4076) {
      tft.fillScreen(TFT_BLACK);
      tft.drawString("Iron Man", 100, 50);
      pixels.setPixelColor(0, pixels.Color(0, 0, 255));
      pixels.show();
      delay(1000);
      tft.drawString("0000", 100, 100);
    } else {
      tft.fillScreen(TFT_BLACK);
      tft.drawString("Access Denied", 50, 50);
      pixels.setPixelColor(0, pixels.Color(255, 0, 0));
      pixels.show();
      delay(1000);
      tft.drawString("0000", 100, 100);
    }
    digit = 0;
    sum = 0;
    num1 = 0;
    num2 = 0;
    num3 = 0;
    num4 = 0;
    text = "";
  }

  if (!digitalRead(SW1)) {
    while (!digitalRead(SW1)) delay(10);
    sound(1200, 200);
    if (digit == 0) num1 = 0 * 1000;
    else if (digit == 1) num2 = 0 * 100;
    else if (digit == 2) num3 = 0 * 10;
    else if (digit == 3) num4 = 0 * 1;
    digit++;
    text = text + "0";
  }
  if (!digitalRead(SW2)) {
    while (!digitalRead(SW2)) delay(10);
    sound(1200, 200);
    if (digit == 0) num1 = 1 * 1000;
    else if (digit == 1) num2 = 1 * 100;
    else if (digit == 2) num3 = 1 * 10;
    else if (digit == 3) num4 = 1 * 1;
    digit++;
    sum = num1 + num2 + num3 + num4;
    text = text + "1";
  }
  if (!digitalRead(SW3)) {
    while (!digitalRead(SW3)) delay(10);
    sound(1200, 200);
    if (digit == 0) num1 = 2 * 1000;
    else if (digit == 1) num2 = 2 * 100;
    else if (digit == 2) num3 = 2 * 10;
    else if (digit == 3) num4 = 2 * 1;
    digit++;
    sum = num1 + num2 + num3 + num4;
    text = text + "2";
  }
  if (!digitalRead(SW4)) {
    while (!digitalRead(SW4)) delay(10);
    sound(1200, 200);
    if (digit == 0) num1 = 3 * 1000;
    else if (digit == 1) num2 = 3 * 100;
    else if (digit == 2) num3 = 3 * 10;
    else if (digit == 3) num4 = 3 * 1;
    digit++;
    text = text + "3";
  }
  if (!digitalRead(SW5)) {
    while (!digitalRead(SW5)) delay(10);
    sound(1200, 200);
    if (digit == 0) num1 = 4 * 1000;
    else if (digit == 1) num2 = 4 * 100;
    else if (digit == 2) num3 = 4 * 10;
    else if (digit == 3) num4 = 4 * 1;
    digit++;
    text = text + "4";
  }
  if (!digitalRead(SW6)) {
    while (!digitalRead(SW6)) delay(10);
    sound(1200, 200);
    if (digit == 0) num1 = 5 * 1000;
    else if (digit == 1) num2 = 5 * 100;
    else if (digit == 2) num3 = 5 * 10;
    else if (digit == 3) num4 = 5 * 1;
    digit++;
    text = text + "5";
  }
  if (!digitalRead(SW7)) {
    while (!digitalRead(SW7)) delay(10);
    sound(1200, 200);
    if (digit == 0) num1 = 6 * 1000;
    else if (digit == 1) num2 = 6 * 100;
    else if (digit == 2) num3 = 6 * 10;
    else if (digit == 3) num4 = 6 * 1;
    digit++;
    text = text + "6";
  }
  if (!digitalRead(SW8)) {
    while (!digitalRead(SW8)) delay(10);
    sound(1200, 200);
    if (digit == 0) num1 = 7 * 1000;
    else if (digit == 1) num2 = 7 * 100;
    else if (digit == 2) num3 = 7 * 10;
    else if (digit == 3) num4 = 7 * 1;
    digit++;
    text = text + "7";
  }
  sum = num1 + num2 + num3 + num4;
  tft.drawString(text, 100, 100);

  delay(100);
}
void __delay_sound(uint16_t ms)  // ฟ งก ชั่ นหน วงเวลาสํ าหรั บสร างสั ญญาณเสี ยง
{
  unsigned int i;
  for (i = 0; i < ms; i++)
    delayMicroseconds(10);
}
void sound(uint16_t freq, uint32_t time)  // ฟ งก ชั่ นกํ าเนิ ดสั ญญาณเสี ยง
{
  uint32_t dt = 0, m = 0;
  uint32_t tempTime;
  pinMode(WIO_BUZZER, OUTPUT);
  digitalWrite(WIO_BUZZER, LOW);
  tempTime = time * 50;
  dt = 50000 / freq;
  time = (tempTime) / dt;
  for (m = 0; m < time; m++) {
    digitalWrite(WIO_BUZZER, HIGH);
    __delay_sound(dt);
    digitalWrite(WIO_BUZZER, LOW);
    __delay_sound(dt);
  }
}
