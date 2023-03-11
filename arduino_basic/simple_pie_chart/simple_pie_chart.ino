#include <TFT_eSPI.h>
#include <SPI.h>  
#include <Histogram.h>

TFT_Histogram histogram = TFT_Histogram();
TFT_eSPI tft;

void setup() {
  tft.begin();
  histogram.initHistogram(&tft);

  histogram.formHistogram("a", 1, 60, 30, TFT_BLUE);
  histogram.formHistogram("b", 2, 30, 40, TFT_RED);
  histogram.formHistogram("c", 3, 90, 40, TFT_YELLOW);
  histogram.formHistogram("d", 4, 70, 50, TFT_GREEN);
  histogram.formHistogram("e", 5, 130, 40, TFT_ORANGE);
  histogram.formHistogram("f", 6, 120, 30, TFT_BLACK);
  histogram.formHistogram("g", 7, 50, 40, TFT_PINK);

  histogram.showHistogram();
  delay(3000);

  histogram.changeParam(5, "E", 55, TFT_RED);
  histogram.deleteCylinder(4);
  histogram.lineChart(TFT_BLACK);

  delay(3000);
  histogram.notShowAxis();
}

void loop() {
}
