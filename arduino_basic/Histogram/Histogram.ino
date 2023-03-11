#include <TFT_eSPI.h>
#include <SPI.h>
#include <Histogram.h>
TFT_Histogram histogram = TFT_Histogram();
TFT_eSPI tft = TFT_eSPI();
void setup() {
  tft.init();
  histogram.initHistogram(&tft);
  histogram.formHistogram("a", 1, 50.55, 40, TFT_RED);
  histogram.formHistogram("b", 2, 20, 40, TFT_BLACK);
  histogram.formHistogram("c", 3, 100, 50, TFT_GREEN);
  histogram.formHistogram("d", 4, 53, 50, TFT_BLUE);
  histogram.formHistogram("e", 5, 133, 30, TFT_YELLOW);
  histogram.formHistogram("f", 6, 53, 50, TFT_ORANGE);
  histogram.formHistogram("g", 7, 80, 50, TFT_PINK);
  histogram.showHistogram();
  delay(3000);
  histogram.changeParam(6, "F", 55, TFT_PINK);
  histogram.deleteCylinder(7);
  histogram.showHistogram();
  histogram.lineChart(TFT_BLACK);
}
void loop() {}