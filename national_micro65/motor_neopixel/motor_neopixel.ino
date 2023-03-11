#include <TFT_eSPI.h>
#include <Adafruit_NeoPixel.h>

#define PIN BCM24
#define NUMPIXELS 12

#define IN1 BCM0
#define IN2 BCM1
#define PWM BCM27

#define VR A2
int pin = 0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
TFT_eSPI tft;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM, OUTPUT);
  pinMode(VR, INPUT);

  tft.begin();
  tft.setRotation(3);
  tft.setTextSize(3);
  pixels.begin();            // This initializes the NeoPixel library.
  pixels.setBrightness(10);  // Set Brightness
  pixels.show();
  tft.fillScreen(TFT_BLACK);
}

void loop() {
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  int val = map(analogRead(VR), 4, 1023, -5, 5);
  int speed_forward = map(val, 0, 5, 0, 255);
  int speed_reverse = map(val, 0, -5, 0, 255);

  if (val == 0) {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 0);
    analogWrite(PWM, 0);
  }
  if (val > 0) {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    analogWrite(PWM, speed_forward);
  }

  if (val < 0) {
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    analogWrite(PWM, speed_reverse);
  }

  tft.drawString("Level", 120, 30);
  tft.drawString("Speed = " + String(val) + "   ", 75, 80);
  if (val >= 0) {
    for (int i = 0; i <= val; i++) {
      pin = i;
      pixels.setPixelColor(6 + i, pixels.Color(255, 0, 0));
      pixels.show();
      continue;
    }
    for (int i = 5; i >= val + 1; i--) {
      pin = i;
      pixels.setPixelColor(6 + i, pixels.Color(0, 0, 0));
      pixels.show();
      continue;
    }
  }
  if (val <= 0) {
    for (int i = 0; i >= val; i--) {
      pin = i;
      pixels.setPixelColor(6 + i, pixels.Color(0, 255, 0));
      pixels.show();
      continue;
    }
    for (int i = -5; i <= val - 1; i++) {
      pin = i;
      pixels.setPixelColor(6 + i, pixels.Color(0, 0, 0));
      pixels.show();
      continue;
    }
  }
  /*for (int i = 5; i >= val; i--) {
    pin = i;
    pixels.setPixelColor(4-i, pixels.Color(0, 0, 0));
    pixels.show();
    continue;
  }*/
  Serial.println(analogRead(VR));
};
