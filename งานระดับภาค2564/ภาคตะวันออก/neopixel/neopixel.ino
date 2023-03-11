#include <Adafruit_NeoPixel.h>
#include <TFT_eSPI.h>
#define PIN BCM27
#define NUMPIXELS 12
#define SW BCM0
TFT_eSPI tft;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int val, pin;
unsigned long previousMillis1 = 0;
byte cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0,
     cnt6 = 0, cnt7 = 0, cnt8 = 0, cnt9 = 0, cnt10 = 0,
     cnt11 = 0, cnt12 = 0;
byte r1, g1, b1,
  r2, g2, b2,
  r3, g3, b3,
  r4, g4, b4,
  r5, g5, b5,
  r6, g6, b6,
  r7, g7, b7,
  r8, g8, b8,
  r9, g9, b9,
  r10, g10, b10,
  r11, g11, b11,
  r12, g12, b12;

void setup() {
  tft.begin();
  pixels.begin();
  pixels.setBrightness(10);
  pixels.show();
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setRotation(3);
  pinMode(A1, INPUT);
  pinMode(SW, INPUT);
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  unsigned long currentMillis = millis();
  val = map(analogRead(A1), 0, 4095, 0, 12);
  if ((currentMillis - previousMillis1) >= 500) {
    tft.fillScreen(TFT_BLACK);
    tft.drawString("Val : " + String(pin), 80, 120);
    previousMillis1 = millis();  // save the "current" time
  }

  if (pin == 1) {
    if (!digitalRead(SW)) {
      while (!digitalRead(SW)) delay(10);
      cnt1++;
      if (cnt1 > 2) cnt1 = 0;
    }
    if (cnt1 == 0) r1 = 255, g1 = 0, b1 = 0;
    if (cnt1 == 1) r1 = 0, g1 = 255, b1 = 0;
    if (cnt1 == 2) r1 = 0, g1 = 0, b1 = 255;
    pixels.setPixelColor(pin - 1, pixels.Color(r1, g1, b1));
  }
  if (pin == 2) {
    if (!digitalRead(SW)) {
      while (!digitalRead(SW)) delay(10);
      cnt2++;
      if (cnt2 > 2) cnt2 = 0;
    }
    if (cnt2 == 0) r2 = 255, g2 = 0, b2 = 0;
    if (cnt2 == 1) r2 = 0, g2 = 255, b2 = 0;
    if (cnt2 == 2) r2 = 0, g2 = 0, b2 = 255;
    pixels.setPixelColor(pin - 1, pixels.Color(r2, g2, b2));
  } 

  if (pin == 3) {
    if (!digitalRead(SW)) {
      while (!digitalRead(SW)) delay(10);
      cnt3++;
      if (cnt3 > 2) cnt3 = 0;
    }
    if (cnt3 == 0) r3 = 255, g3 = 0, b3 = 0;
    if (cnt3 == 1) r3 = 0, g3 = 255, b3 = 0;
    if (cnt3 == 2) r3 = 0, g3 = 0, b3 = 255;
    pixels.setPixelColor(pin - 1, pixels.Color(r3, g3, b3));
  } 

  if (pin == 4) {
    if (!digitalRead(SW)) {
      while (!digitalRead(SW)) delay(10);
      cnt4++;
      if (cnt4 > 2) cnt4 = 0;
    }
    if (cnt4 == 0) r4 = 255, g4 = 0, b4 = 0;
    if (cnt4 == 1) r4 = 0, g4 = 255, b4 = 0;
    if (cnt4 == 2) r4 = 0, g4 = 0, b4 = 255;
    pixels.setPixelColor(pin - 1, pixels.Color(r4, g4, b4));
  } 

  if (pin == 5) {
    if (!digitalRead(SW)) {
      while (!digitalRead(SW)) delay(10);
      cnt5++;
      if (cnt5 > 2) cnt5 = 0;
    }
    if (cnt5 == 0) r5 = 255, g5 = 0, b5 = 0;
    if (cnt5 == 1) r5 = 0, g5 = 255, b5 = 0;
    if (cnt5 == 2) r5 = 0, g5 = 0, b5 = 255;
    pixels.setPixelColor(pin - 1, pixels.Color(r5, g5, b5));
  } 

  if (pin == 6) {
    if (!digitalRead(SW)) {
      while (!digitalRead(SW)) delay(10);
      cnt6++;
      if (cnt6 > 2) cnt6 = 0;
    }
    if (cnt6 == 0) r6 = 255, g6 = 0, b6 = 0;
    if (cnt6 == 1) r6 = 0, g6 = 255, b6 = 0;
    if (cnt6 == 2) r6 = 0, g6 = 0, b6 = 255;
    pixels.setPixelColor(pin - 1, pixels.Color(r6, g6, b6));
  } 

  if (pin == 7) {
    if (!digitalRead(SW)) {
      while (!digitalRead(SW)) delay(10);
      cnt7++;
      if (cnt7 > 2) cnt7 = 0;
    }
    if (cnt7 == 0) r7 = 255, g7 = 0, b7 = 0;
    if (cnt7 == 1) r7 = 0, g7 = 255, b7 = 0;
    if (cnt7 == 2) r7 = 0, g7 = 0, b7 = 255;
    pixels.setPixelColor(pin - 1, pixels.Color(r7, g7, b7));
  } 

  if (pin == 8) {
    if (!digitalRead(SW)) {
      while (!digitalRead(SW)) delay(10);
      cnt8++;
      if (cnt8 > 2) cnt8 = 0;
    }
    if (cnt8 == 0) r8 = 255, g8 = 0, b8 = 0;
    if (cnt8 == 1) r8 = 0, g8 = 255, b8 = 0;
    if (cnt8 == 2) r8 = 0, g8 = 0, b8 = 255;
    pixels.setPixelColor(pin - 1, pixels.Color(r8, g8, b8));
  } 

  if (pin == 9) {
    if (!digitalRead(SW)) {
      while (!digitalRead(SW)) delay(10);
      cnt9++;
      if (cnt9 > 2) cnt9 = 0;
    }
    if (cnt9 == 0) r9 = 255, g9 = 0, b9 = 0;
    if (cnt9 == 1) r9 = 0, g9 = 255, b9 = 0;
    if (cnt9 == 2) r9 = 0, g9 = 0, b9 = 255;
    pixels.setPixelColor(pin - 1, pixels.Color(r9, g9, b9));
  } 

  if (pin == 10) {
    if (!digitalRead(SW)) {
      while (!digitalRead(SW)) delay(10);
      cnt10++;
      if (cnt10 > 2) cnt10 = 0;
    }
    if (cnt10 == 0) r10 = 255, g10 = 0, b10 = 0;
    if (cnt10 == 1) r10 = 0, g10 = 255, b10 = 0;
    if (cnt10 == 2) r10 = 0, g10 = 0, b10 = 255;
    pixels.setPixelColor(pin - 1, pixels.Color(r10, g10, b10));
  } 

  if (pin == 11) {
    if (!digitalRead(SW)) {
      while (!digitalRead(SW)) delay(10);
      cnt11++;
      if (cnt11 > 2) cnt11 = 0;
    }
    if (cnt11 == 0) r11 = 255, g11 = 0, b11 = 0;
    if (cnt11 == 1) r11 = 0, g11 = 255, b11 = 0;
    if (cnt11 == 2) r11 = 0, g11 = 0, b11 = 255;
    pixels.setPixelColor(pin - 1, pixels.Color(r11, g11, b11));
  } 

  if (pin == 12) {
    if (!digitalRead(SW)) {
      while (!digitalRead(SW)) delay(10);
      cnt12++;
      if (cnt12 > 2) cnt12 = 0;
    }
    if (cnt12 == 0) r12 = 255, g12 = 0, b12 = 0;
    if (cnt12 == 1) r12 = 0, g12 = 255, b12 = 0;
    if (cnt12 == 2) r12 = 0, g12 = 0, b12 = 255;
    pixels.setPixelColor(pin - 1, pixels.Color(r12, g12, b12));
  } 

  for (int i = 0; i <= val; i++) {
    pin = i;
    continue;
  }
  for (int i = 11; i >= val; i--) {
    pin = i;
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    Serial.println("LED OFF");
    continue;
  }
  Serial.println(pin);
  pixels.show();
  Serial.println(val);
  delay(100);
};