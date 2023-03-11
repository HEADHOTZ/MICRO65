#include <M5Stack.h>

#include <FastLED.h>

#define DATA_PIN 15
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS 64
CRGB leds[NUM_LEDS];
#define BRIGHTNESS 5

int num0[20] = {3, 4, 5, 10, 18, 26, 34, 42, 50, 59, 60, 61, 54, 55, 47, 39, 31, 23, 14} ; // 0
int num1[10] = {4, 11, 12, 20, 28, 36, 44, 52, 60} ;  // 1
int num2[14] = {11, 3, 4,  5, 13, 21, 29, 36, 43, 51, 59, 60, 61} ; // 2
int num3[17] = {11, 3, 4, 5, 13, 21, 27, 28, 35, 36, 45, 53, 61, 60, 59, 51} ; // 3

/* ------------------------------------------------------------------------ */
void setup() {
  Serial.begin(115200);
  M5.begin();

  M5.Lcd.setCursor(50, 70, 4);
  M5.Lcd.println("RECIVE IS NUMBER");
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  Serial.println();
  Serial.println("Input Your String : ");
  ClrRGB();    // CLR RGB ON Start
};

void loop() {
  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('\n');
    Serial.println(str);
    ClrRGB();   // Crl RGB Befor Show NUM
    // -----------------------------
    if (str == "1" or str == "one") {
      NUM1();
      M5.Lcd.setCursor(80, 120, 4);
      M5.Lcd.println("NUMBER IS : 1");
      Serial.println("RGB IS : 1");
    }
    if (str == "2" || str == "two") {
      NUM2();
      M5.Lcd.setCursor(80, 120, 4);
      M5.Lcd.println("NUMBER IS : 2");
      Serial.println("RGB IS : 2");
    }
    if (str == "3" or str == "three") {
      NUM3();
      M5.Lcd.setCursor(80, 120, 4);
      M5.Lcd.println("NUMBER IS : 3");
      Serial.println("RGB IS : 3");
    }
    // ------------------------------
  }
  delay(10);
};
/* ------------------------------------------------------------------ */

/* ======================   Subrutine Or Function Programs   ========================  */
void NUM1() {
  for (int i = 0; i < 9; i++) {
    leds[num1[i]] = CRGB::Red;
    FastLED.show();
  }
};
void NUM2() {
  for (int i = 0; i < 13; i++) {
    leds[num2[i]] = CRGB::Red;
    FastLED.show();
  }
};
void NUM3() {
  for (int i = 0; i < 16; i++) {
    leds[num3[i]] = CRGB::Red;
    FastLED.show();
  }
};
void ClrRGB() {
  for (int i = 0; i < 64; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();
  }
};
