#include <Adafruit_NeoPixel.h>
#include <TFT_eSPI.h>
#define PIN BCM27
#define NUMPIXELS 12
#define VR A1
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
TFT_eSPI tft;
int pin;
unsigned long previousMillis1 = 0;

void setup() {
  tft.begin();
  pixels.begin();
  pixels.setBrightness(10);
  pixels.show();
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(3);
  tft.setRotation(3);
  pinMode(VR, INPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();
  int adc = analogRead(VR);
  int val = map(adc, 2, 1023, 0, 12);
  int num = val;
  tft.drawString(String(val) + String("   "), 130, 150);
  if (pin == 1) {
    pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    pixels.show();
  }
  if (pin == 2) {
    pixels.setPixelColor(pin - 1, pixels.Color(0, 255, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 255, 0));
    pixels.show();
  }
  if (pin == 3) {
    pixels.setPixelColor(pin - 1, pixels.Color(255, 242, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(255, 242, 0));
    pixels.show();
  }
  if (pin == 4) {
    pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    pixels.show();
  }
  if (pin == 5) {
    pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    pixels.show();
  }
  if (pin == 6) {
    pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    pixels.show();
  }
  if (pin == 7) {
    pixels.setPixelColor(pin - 1, pixels.Color(0, 255, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 255, 0));
    pixels.show();
  }
  if (pin == 8) {
    pixels.setPixelColor(pin - 1, pixels.Color(0, 255, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 255, 0));
    pixels.show();
  }
  if (pin == 9) {
    pixels.setPixelColor(pin - 1, pixels.Color(0, 255, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 255, 0));
    pixels.show();
  }
  if (pin == 10) {
    pixels.setPixelColor(pin - 1, pixels.Color(255, 242, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(255, 242, 0));
    pixels.show();
  }
  if (pin == 11) {
    pixels.setPixelColor(pin - 1, pixels.Color(255, 242, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(255, 242, 0));
    pixels.show();
  }

  if (pin == 12) {
    pixels.setPixelColor(pin - 1, pixels.Color(255, 242, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(255, 242, 0));
    pixels.show();
  }

  for (int i = 0; i <= val; i++) {
    pin = i;
    continue;
  }
  for (int i = 11; i >= val; i--) {
    pin = i;
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    continue;
  }
  pixels.show();
  tft.drawString("Level", 120, 50);
  Serial.println(pin);
  /*if ((currentMillis - previousMillis1) >= 1) {
    tft.fillScreen(TFT_BLACK);
    tft.drawString(String(pin) + String("   "), 130, 150);
    previousMillis1 = millis();
  }*/
}
