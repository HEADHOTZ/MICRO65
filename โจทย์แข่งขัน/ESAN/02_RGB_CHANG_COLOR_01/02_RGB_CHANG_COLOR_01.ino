#include <Adafruit_NeoPixel.h>

#define PIN        D7   
#define Sw         D8
#define NUMPIXELS 12   //  NeoPixel ring size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

byte i = 0;            // Switch Case To Chang Color RGB
byte R, G, B, n;
int adc, adcMap;

/* *************************************************************************** */
void setup() {
  pinMode(Sw, INPUT);
  //Serial.begin(9600);
  pixels.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(10);
  pixels.clear();           // Set all pixel colors to 'off'
};
/* *************************************************************************** */
void loop() {
  // -------------------------------------------------- //
  if (digitalRead(Sw) == 0) {
    while (digitalRead(Sw) == 0) delay(10);
    i++;
    if (i > 2) i = 0;
  }
  // ---------------  Chang Color -------------------- //
  switch (i) {
    case 0:
      R = 255;  G = 0;    B = 0;
      break;
    case 1:
      R = 0;    G = 255;  B = 0;
      break;
    case 2:
      R = 0;    G = 0;    B = 255;
      break;
  }// Switch
  // ------------------------------------------------ //
  adc = analogRead(A0);             // 10Bit : 0-1023
  adcMap = map(analogRead(A0), 0, 1023, 0, 1200);
  //Serial.println("adcMap:"+String(adcMap));

  if(adcMap < 10){
      pixels.clear();
  }
  if (adcMap > 10 and adcMap < 100) {
    n = 0;
    pixels.clear();
  }
  if (adcMap > 100  and adcMap < 200) {
    n = 1;
    pixels.clear();
  }
  if (adcMap > 200  and adcMap < 300) {
    n = 2;
    pixels.clear();
  }
  if (adcMap > 301  and adcMap < 400) {
    n = 3;
    pixels.clear();
  }
  if (adcMap > 400  and adcMap < 500) {
    n = 4;
    pixels.clear();
  }
  if (adcMap > 501  and adcMap < 600) {
    n = 5;
    pixels.clear();
  }
  if (adcMap > 600  and adcMap < 700) {
    n = 6;
    pixels.clear();
  }
  if (adcMap > 700  and adcMap < 800) {
    n = 7;
    pixels.clear();
  }
  if (adcMap > 800  and adcMap < 900) {
    n = 8;
    pixels.clear();
  }
  if (adcMap > 901  and adcMap < 1000) {
    n = 9;
    pixels.clear();
  }
  if (adcMap > 1000 and adcMap < 1100) {
    n = 10;
    pixels.clear();
  }
  if (adcMap > 1100 and adcMap < 1200) {
    n = 11;
    pixels.clear();
  }
  pixels.setPixelColor(n , pixels.Color(R, G, B));     // 0-11,RGB:0-255
  pixels.show();
  delay(10);
};
/* *************************************************************************** */
