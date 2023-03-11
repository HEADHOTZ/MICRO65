#include <TFT_eSPI.h>
#include <SPI.h>
#include <Histogram.h>

TFT_Histogram histogram = TFT_Histogram();
TFT_eSPI tft;

bool update_val = false;
int val1;
int last_val1;

int val2;
int last_val2;

int val3;
int last_val3;

void setup() {
  tft.begin();
  histogram.initHistogram(&tft);
  analogReadResolution(12);
  histogram.formHistogram("VR1", 1, val1, 40, TFT_RED);
  histogram.formHistogram("VR2", 2, val2, 40, TFT_BLUE);
  histogram.formHistogram("VR3", 3, val3, 40, TFT_GREEN);
  histogram.showHistogram();
}

void loop() {
  val1 = map(analogRead(A0), 10, 4095, 0, 4095);
  val2 = map(analogRead(A1), 10, 4095, 0, 4095);
  val3 = map(analogRead(A2), 10, 4095, 0, 4095);
  if (val1 != last_val1) {
    histogram.changeParam(1, "VR1", val1, TFT_RED);
    last_val1 = val1;
  }
  if (val2 != last_val2) {
    histogram.changeParam(2, "VR2", val2, TFT_BLUE);
    last_val2 = val2;
  }
  if (val3 != last_val3) {
    histogram.changeParam(3, "VR3", val3, TFT_GREEN);
    last_val3 = val3;
  }
  //Serial.println(analogRead(A0));
  //Serial.println(analogRead(A1));
  Serial.println(analogRead(A2));
  delay(500);
}