#include <TFT_eSPI.h>
TFT_eSPI tft;
//---------------------------------//
#define SW1 BCM0
#define SW2 BCM1
#define SW3 BCM2
#define SW4 BCM3
#define SW5 BCM4
#define RY1 BCM5
#define RY2 BCM6
#define RY3 BCM7
#define RY4 BCM8
//---------------------------------//
int Timer = 0;
bool state = 0;
//----------------------------------//
/***********************************************/

void setup() {
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(3);
  //--------------------------------------------//
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
  pinMode(SW5, INPUT);
  pinMode(RY1, OUTPUT);
  pinMode(RY2, OUTPUT);
  pinMode(RY3, OUTPUT);
  pinMode(RY4, OUTPUT);

  Serial.begin(115200);
};

void loop() {
  tft.drawString("Relay", 100, 10);
  tft.drawString("R1", 20, 50);
  tft.drawString("R2", 100, 50);
  tft.drawString("R3", 180, 50);
  tft.drawString("R4", 260, 50);
  if (digitalRead(RY1) == 1) tft.drawString("ON", 20, 110);
  else tft.drawString("OFF", 20, 110);
  if (digitalRead(RY2) == 1) tft.drawString("ON", 100, 110);
  else tft.drawString("OFF", 100, 110);
  if (digitalRead(RY3) == 1) tft.drawString("ON", 180, 110);
  else tft.drawString("OFF", 180, 110);
  if (digitalRead(RY4) == 1) tft.drawString("ON", 260, 110);
  else tft.drawString("OFF", 260, 110);
  if (!digitalRead(SW1)) {
    Timer++;
    Serial.println(Timer);
    if (Timer % 3 == 0) {
      digitalWrite(RY1, !digitalRead(RY1));
      tft.drawString("   ", 20, 110);
    }
  } else if (!digitalRead(SW2)) {
    Timer++;
    Serial.println(Timer);
    if (Timer % 3 == 0) {
      digitalWrite(RY2, !digitalRead(RY2));
      tft.drawString("   ", 100, 110);
    }
  } else if (!digitalRead(SW3)) {
    Timer++;
    Serial.println(Timer);
    if (Timer % 3 == 0) {
      digitalWrite(RY3, !digitalRead(RY3));
      tft.drawString("   ", 180, 110);
    }
  } else if (!digitalRead(SW4)) {
    Timer++;
    Serial.println(Timer);
    if (Timer % 3 == 0) {
      digitalWrite(RY4, !digitalRead(RY4));
      tft.drawString("   ", 260, 110);
    }
  } else if (!digitalRead(SW5)) {
    Timer++;
    Serial.println(Timer);
    if (Timer % 3 == 0) {
      state = !state;
      digitalWrite(RY1, state);
      digitalWrite(RY2, state);
      digitalWrite(RY3, state);
      digitalWrite(RY4, state);
      tft.fillScreen(TFT_BLACK);
    }
  } else Timer = 0;
  delay(1000);
}
