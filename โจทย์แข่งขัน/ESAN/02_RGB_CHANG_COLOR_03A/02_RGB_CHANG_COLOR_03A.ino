#include <Adafruit_NeoPixel.h>
// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        D7 // On Trinket or Gemma, suggest changing this to 1
#define Sw         D8

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 12          //  NeoPixel ring size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

byte i = 0;     // Switch Case To Chang Color RGB
byte R, G, B, n;
int adc, adcMap;
/* *************************************************************************** */
void setup() {
  pinMode(Sw, INPUT);

  Serial.begin(9600);

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
  adcMap = map(adc, 0, 1023, 0, 1200);
  Serial.println("adcMap:" + String(adcMap));
  if (adcMap < 10) { // 0
    pixels.setPixelColor(0 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(1 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(2 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(3 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(4 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(5 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(8 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(9 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(10 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(11 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.show();
  }
  if (adcMap > 10 and adcMap < 100) { // 0
    pixels.setPixelColor(0 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(1 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(2 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(3 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(4 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(5 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(8 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(9 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(10 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(11 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.show();
  }
  if (adcMap > 100  and adcMap < 200) { // 1
    pixels.setPixelColor(0 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(1 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(2 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(3 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(4 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(5 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(8 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(9 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(10 , pixels.Color(0, 0, 0));    
    pixels.setPixelColor(11 , pixels.Color(0, 0, 0));     
    pixels.show();
  }
  if (adcMap > 201  and adcMap < 300) {  // 2
    pixels.setPixelColor(0 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(1 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(2 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(3 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(4 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(5 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(8 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(9 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(10 , pixels.Color(0, 0, 0));    // 0-11,RGB:0-255
    pixels.setPixelColor(11 , pixels.Color(0, 0, 0));    // 0-11,RGB:0-255
    pixels.show();
  }
  if (adcMap > 301  and adcMap < 400) {  // 3
    pixels.setPixelColor(0 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(1 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(2 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(3 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(4 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(5 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(8 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(9 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(10 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(11 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.show();
  }
  if (adcMap > 401  and adcMap < 500) {  // 4
    pixels.setPixelColor(0 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(1 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(2 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(3 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(4 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(5 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(8 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(9 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(10 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(11 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.show();
  }
  if (adcMap > 501  and adcMap < 600) {  // 5
    pixels.setPixelColor(0 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(1 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(2 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(3 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(4 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(5 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(8 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(9 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(10 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(11 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.show();
  }
  if (adcMap > 601  and adcMap < 700) {  // 6
    pixels.setPixelColor(0 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(1 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(2 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(3 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(4 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(5 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(8 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(9 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(10 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(11 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.show();
  }
  if (adcMap > 701  and adcMap < 800) {  // 7
    pixels.setPixelColor(0 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(1 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(2 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(3 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(4 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(5 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(8 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(9 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(10 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(11 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.show();
  }
  if (adcMap > 801  and adcMap < 900) {  // 8
    pixels.setPixelColor(0 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(1 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(2 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(3 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(4 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(5 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(8 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(9 ,  pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(10 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(11 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.show();
  }
  if (adcMap > 900  and adcMap < 1000) {  // 9
    pixels.setPixelColor(0 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(1 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(2 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(3 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(4 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(5 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(8 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(9 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(10 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.setPixelColor(11 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.show();
  }
  if (adcMap > 1000  and adcMap < 1100) {  // 10
    pixels.setPixelColor(0 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(1 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(2 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(3 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(4 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(5 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(8 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(9 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(10 , pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(11 , pixels.Color(0, 0, 0));     // 0-11,RGB:0-255
    pixels.show();
  }
  if (adcMap > 1101  and adcMap <= 1200) {  // 11
    pixels.setPixelColor(0 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(1 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(2 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(3 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(4 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(5 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(6 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(7 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(8 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(9 ,  pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(10 , pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.setPixelColor(11 , pixels.Color(R, G, B));     // 0-11,RGB:0-255
    pixels.show();
  }
  delay(10);
};
/* *************************************************************************** */
