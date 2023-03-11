#include <Adafruit_NeoPixel.h>
#include <TFT_eSPI.h>
#define PIN BCM27
#define NUMPIXELS 12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
TFT_eSPI tft;
int pin;

void setup() {
  tft.begin();
  pixels.begin();
  pixels.setBrightness(10);
  pixels.show();
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(3);
  tft.setRotation(3);
  pinMode(A1, INPUT);
  pinMode(WIO_BUZZER, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int val = map(analogRead(A1), 2, 1023, 0, 12);
  if (pin == 0) {
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));
    pixels.show();
  }
  if (pin == 1) {
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));
    pixels.show();
  }
  if (pin == 2) {
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
    pixels.show();
  }
  if (pin == 3) {
    pixels.setPixelColor(3, pixels.Color(0, 0, 255));
    pixels.show();
  }
  if (pin == 4) {
    pixels.setPixelColor(4, pixels.Color(255, 0, 0));
    pixels.show();
  }
  if (pin == 5) {
    pixels.setPixelColor(5, pixels.Color(0, 255, 0));
    pixels.show();
  }
  if (pin == 6) {
    pixels.setPixelColor(6, pixels.Color(0, 0, 255));
    pixels.show();
  }
  if (pin == 7) {
    pixels.setPixelColor(7, pixels.Color(255, 0, 0));
    pixels.show();
  }
  if (pin == 8) {
    pixels.setPixelColor(8, pixels.Color(0, 255, 0));
    pixels.show();
  }
  if (pin > 8) {
    alert();
  }
  for (int i = 0; i <= val; i++) {
    pin = i;
    //pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    continue;
  }
  for (int i = 11; i >= val; i--) {
    pin = i;
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    continue;
  }
  Serial.println(pin);
}

void alert() {
  pixels.setPixelColor(1, pixels.Color(255, 0, 0));
  pixels.setPixelColor(2, pixels.Color(0, 255, 0));
  pixels.setPixelColor(3, pixels.Color(0, 0, 255));
  pixels.setPixelColor(4, pixels.Color(255, 0, 0));
  pixels.setPixelColor(5, pixels.Color(0, 255, 0));
  pixels.setPixelColor(6, pixels.Color(0, 0, 255));
  pixels.setPixelColor(7, pixels.Color(255, 0, 0));
  pixels.setPixelColor(8, pixels.Color(0, 255, 0));
  analogWrite(WIO_BUZZER, 50);
  pixels.show();
  delay(50);
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.setPixelColor(2, pixels.Color(0, 0, 0));
  pixels.setPixelColor(3, pixels.Color(0, 0, 0));
  pixels.setPixelColor(4, pixels.Color(0, 0, 0));
  pixels.setPixelColor(5, pixels.Color(0, 0, 0));
  pixels.setPixelColor(6, pixels.Color(0, 0, 0));
  pixels.setPixelColor(7, pixels.Color(0, 0, 0));
  pixels.setPixelColor(8, pixels.Color(0, 0, 0));
  pixels.show();
  analogWrite(WIO_BUZZER, 0);
  delay(50);
  pixels.setPixelColor(1, pixels.Color(255, 0, 0));
  pixels.setPixelColor(2, pixels.Color(0, 255, 0));
  pixels.setPixelColor(3, pixels.Color(0, 0, 255));
  pixels.setPixelColor(4, pixels.Color(255, 0, 0));
  pixels.setPixelColor(5, pixels.Color(0, 255, 0));
  pixels.setPixelColor(6, pixels.Color(0, 0, 255));
  pixels.setPixelColor(7, pixels.Color(255, 0, 0));
  pixels.setPixelColor(8, pixels.Color(0, 255, 0));
  pixels.show();
}