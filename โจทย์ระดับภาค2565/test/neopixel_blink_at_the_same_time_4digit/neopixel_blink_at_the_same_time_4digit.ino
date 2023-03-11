#include <Adafruit_NeoPixel.h>
#include <TFT_eSPI.h>
#define PIN BCM27
#define NUMPIXELS 12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
TFT_eSPI tft;
int pin;
unsigned long previousMillis1 = 0;
bool state1 = 0;
bool state2 = 0;
bool state3 = 0;
bool state4 = 0;

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
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();
  int val = map(analogRead(A1), 2, 1023, 0, 12);
  if(pin < 9) {
    state1 = 0;
    state2 = 0;
    state3 = 0;
    state4 = 0;
  }
  if (pin == 1) {
    pixels.setPixelColor(pin - 1, pixels.Color(0, 255, 0));
  }
  if (pin == 2) {
    pixels.setPixelColor(pin - 1, pixels.Color(0, 255, 0));
  }
  if (pin == 3) {
    pixels.setPixelColor(pin - 1, pixels.Color(0, 255, 0));
  }
  if (pin == 4) {
    pixels.setPixelColor(pin - 1, pixels.Color(0, 255, 0));
  }
  if (pin == 5) {
    pixels.setPixelColor(pin - 1, pixels.Color(255, 253, 0));
    pixels.show();
  }
  if (pin == 6) {
    pixels.setPixelColor(pin - 1, pixels.Color(255, 253, 0));
    pixels.show();
  }
  if (pin == 7) {
    pixels.setPixelColor(pin - 1, pixels.Color(255, 253, 0));
    pixels.show();
  }
  if (pin == 8) {
    pixels.setPixelColor(pin - 1, pixels.Color(255, 253, 0));
    pixels.show();
  }
  if (pin == 9) {
    state1 = 1;
    /*pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    pixels.show();*/
  }
  if (pin == 10) {
    state2 = 1;
    /*pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    pixels.show();*/
  }
  if (pin == 11) {
    state3 = 1;
    /*pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    pixels.show();*/
  }

  if (pin == 12) {
    state4 = 1;
    /*pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(0, 0, 0));
    pixels.show();
    delay(50);
    pixels.setPixelColor(pin - 1, pixels.Color(255, 0, 0));
    pixels.show();*/
  }
  if (pin > 8) {
    if (state1 == 1) {
      pixels.setPixelColor(8, pixels.Color(255, 0, 0));
      delay(50);
      pixels.setPixelColor(8, pixels.Color(0, 0, 0));
      pixels.show();
      delay(50);
      pixels.setPixelColor(8, pixels.Color(255, 0, 0));
      pixels.show();
    }
    if (state2 == 1) {
      pixels.setPixelColor(9, pixels.Color(255, 0, 0));
      delay(50);
      pixels.setPixelColor(9, pixels.Color(0, 0, 0));
      pixels.show();
      delay(50);
      pixels.setPixelColor(9, pixels.Color(255, 0, 0));
      pixels.show();
    }
    if (state3 == 1) {
      pixels.setPixelColor(10, pixels.Color(255, 0, 0));
      delay(50);
      pixels.setPixelColor(10, pixels.Color(0, 0, 0));
      pixels.show();
      delay(50);
      pixels.setPixelColor(10, pixels.Color(255, 0, 0));
      pixels.show();
    }
    if (state4 == 1) {
      pixels.setPixelColor(11, pixels.Color(255, 0, 0));
      delay(50);
      pixels.setPixelColor(11, pixels.Color(0, 0, 0));
      pixels.show();
      delay(50);
      pixels.setPixelColor(11, pixels.Color(255, 0, 0));
      pixels.show();
    }
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
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString(String(pin) + String("   "), 130, 150);
}
/*NOTE ลองเพิ่มค่าสถานะที่เทียบกับ pin ค่าเก่า ถ้าน้อยลงให้ state เป็น 0
