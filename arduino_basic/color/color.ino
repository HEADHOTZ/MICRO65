#include <TFT_eSPI.h>
#include <Adafruit_NeoPixel.h>

#define PIN BCM22
#define NUMPIXELS 12

#define SW1 BCM0
#define SW2 BCM1

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
TFT_eSPI tft;

byte colorArray[18] = {
  255, 0, 0,      // Red
  0, 255, 0,      // Green
  0, 0, 255,      //  BLUE
  255, 253, 85,   //  YELLOW
  255, 255, 255,  //  WHITE
  0, 0, 0         //  OFF
};

bool state1 = 0;
int last_val;

void setup() {
  pinMode(A0, INPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);

  tft.begin();
  tft.setRotation(3);
  tft.setTextSize(3);
  pixels.begin();            // This initializes the NeoPixel library.
  pixels.setBrightness(10);  // Set Brightness
  pixels.show();
}

void loop() {
  int val = map(analogRead(A0), 2, 1023, 0, 5);
  if (last_val != val) {
    state1 = 0;
    last_val = val;
  }
  if (state1 == 0) {
    if (val == 0) tft.fillScreen(TFT_RED);
    if (val == 1) tft.fillScreen(TFT_GREEN);
    if (val == 2) tft.fillScreen(TFT_BLUE);
    if (val == 3) tft.fillScreen(TFT_YELLOW);
    if (val == 4) tft.fillScreen(TFT_WHITE);
    if (val == 5) tft.fillScreen(TFT_BLACK);
    state1 = 1;
  }
  switch (val) {
    case 0:
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("COLOR", 100, 50);
      tft.drawString("RED", 120, 100);
      break;
    case 1:
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("COLOR", 100, 50);
      tft.drawString("GREEN", 100, 100);
      break;
    case 2:
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("COLOR", 100, 50);
      tft.drawString("BLUE", 120, 100);
      break;
    case 3:
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("COLOR", 100, 50);
      tft.drawString("YELLOW", 100, 100);
      break;
    case 4:
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("COLOR", 100, 50);
      tft.drawString("WHITE", 120, 100);
      break;
    case 5:
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("COLOR", 100, 50);
      tft.drawString("OFF", 120, 100);
      break;
  }
  if (!digitalRead(SW1)) {
    while (!digitalRead(SW1)) delay(10);
    pixels.setPixelColor(0, colorArray[val * 3], colorArray[(val * 3) + 1], colorArray[(val * 3) + 2]);
    pixels.show();
  }
  if (!digitalRead(SW2)) {
    while (!digitalRead(SW2)) delay(10);
    pixels.setPixelColor(1, colorArray[val * 3], colorArray[(val * 3) + 1], colorArray[(val * 3) + 2]);
    pixels.show();
  }
}
