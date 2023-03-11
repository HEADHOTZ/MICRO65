#include <TFT_eSPI.h>
TFT_eSPI tft;

#define SW1 BCM0
#define SW2 BCM1
#define SW3 BCM2
#define SW4 BCM3
#define SW5 BCM9
#define RY1 BCM5
#define RY2 BCM6
#define RY3 BCM7
#define RY4 BCM8

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;
unsigned long currentMillis = 0;

void setup() {
  tft.begin();
  tft.setRotation(3);
  tft.setTextSize(2);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
  pinMode(RY1, OUTPUT);
  pinMode(RY2, OUTPUT);
  pinMode(RY3, OUTPUT);
  pinMode(RY4, OUTPUT);
};

void loop() {
  currentMillis = millis();
  if (digitalRead(SW1) == 0) {
    if ((currentMillis - previousMillis1) >= 3000) {
      digitalWrite(RY1, !digitalRead(RY1));
      Serial.println(currentMillis - previousMillis1);
      previousMillis1 = millis();
    }
  }
  if (!digitalRead(SW2)) {
    currentMillis = millis();
    if ((currentMillis - previousMillis2) >= 3000) {
      digitalWrite(RY2, !digitalRead(RY2));
      //Serial.println("IN");
      previousMillis2 = millis();
    }
  }
  if (!digitalRead(SW3)) {
    currentMillis = millis();
    if ((currentMillis - previousMillis3) >= 3000) {
      digitalWrite(RY3, !digitalRead(RY3));
      //Serial.println("IN");
      previousMillis3 = millis();
    }
  }
  if (!digitalRead(SW4)) {
    currentMillis = millis();
    if ((currentMillis - previousMillis4) >= 3000) {
      digitalWrite(RY4, !digitalRead(RY4));
      //Serial.println("IN");
      previousMillis4 = millis();
    }
  }


  //Serial.println(SW1);
};
