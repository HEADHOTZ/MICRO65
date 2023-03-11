#include <TFT_eSPI.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
TFT_eSPI tft;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
int cnt = 0;

void setup() {
  mlx.begin();
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);  //sets the text colour to black
  tft.setTextSize(3);
  tft.drawString(String("Count : 0") + String(" / 5   "), 50, 200);
  Serial.begin(115200);
}

void loop() {
  float objTempC = mlx.readObjectTempC();
  tft.drawString(String("Object: ") + String(objTempC) + String(" C   "), 50, 150);
  if (objTempC > 26.5) {
    cnt += 1;   //  นับค่าทันทีที่วัดค่าได้
    while (objTempC > 26.5) {
      float objTempC = mlx.readObjectTempC();
      if (objTempC < 26.5) {
        //cnt += 1;   //  นับค่าหลังจากปล่อยมือ
        break;
      }
      tft.drawString(String("Object: ") + String(objTempC) + String(" C   "), 50, 150);
      tft.drawString(String("Count : ") + String(cnt) + String(" / 5   "), 50, 200);
    }
  }
  if (cnt > 5) {
    tft.drawString(String("Count : FULL") + String("    "), 50, 200);
    delay(300);
    cnt = 0;
    tft.drawString(String("Count : ") + String(cnt) + String(" / 5   "), 50, 200);
  }
  else tft.drawString(String("Count : ") + String(cnt) + String(" / 5   "), 50, 200);
}
