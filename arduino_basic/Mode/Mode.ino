#include "TFT_eSPI.h"
TFT_eSPI tft;

#include <Servo.h>
Servo myservo;

#include <DHT.h>
#define DHTPIN BCM0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int cntCursor = 1;
byte mode;

bool toggle_buzzer;
int val;
/* ------------------------------------------------------------------------ */
void setup() {
  pinMode(WIO_5S_UP, INPUT_PULLUP);
  pinMode(WIO_5S_DOWN, INPUT_PULLUP);
  pinMode(WIO_5S_LEFT, INPUT_PULLUP);
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);
  pinMode(WIO_BUZZER, OUTPUT);

  myservo.attach(BCM9);
  myservo.write(0);

  dht.begin();

  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);

  Serial.begin(115200);
};
/* ------------------------------------------------------------------------ */
void loop() {
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.setTextSize(2);
  tft.drawString("SPEAKER ", 50, 30);
  tft.drawString("SERVO   ", 50, 80);
  tft.drawString("DHT     ", 50, 130);

  Cursor();
  mode_Speaker();
  mode_Servo();
  mode_DHT();
  delay(10);
};
/* ------------------------------------------------------------------------ */
void Cursor() {
  // ---------------  Cnt to Cursor  ------------
  if (digitalRead(WIO_5S_DOWN) == LOW) {
    while (digitalRead(WIO_5S_DOWN) == LOW) delay(10);
    Serial.println("5 Way Up");
    tft.fillScreen(TFT_BLACK);  // Clr Cursor
    cntCursor++;
    if (cntCursor >= 3) cntCursor = 3;
  } else if (digitalRead(WIO_5S_UP) == LOW) {
    while (digitalRead(WIO_5S_UP) == LOW) delay(10);
    Serial.println("5 Way Down");
    tft.fillScreen(TFT_BLACK);  // Clr Cursor
    cntCursor--;
    if (cntCursor <= 1) cntCursor = 1;
  }
  // ----------- Showe Cursor Of Position -------
  if (cntCursor == 1) {
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.drawString(" > ", 10, 30);
  }
  if (cntCursor == 2) {
    tft.drawString(" > ", 10, 80);
  }
  if (cntCursor == 3) {
    tft.drawString(" > ", 10, 130);
  }
};
/* ------------------------------------------------------------------------ */

void mode_Speaker() {
  if (toggle_buzzer == 1) analogWrite(WIO_BUZZER, 50);
  else analogWrite(WIO_BUZZER, 0);
  if (cntCursor == 1 && digitalRead(WIO_5S_PRESS) == LOW) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(3);
    tft.drawString("Buzzer : ", 50, 80);
    mode = 1;
  }
  while (mode == 1) {
    bool state;
    if (digitalRead(WIO_5S_UP) == LOW) {
      tft.drawString("Buzzer : ON   ", 50, 80);
      analogWrite(WIO_BUZZER, 50);
      state = 1;
    }
    if (digitalRead(WIO_5S_DOWN) == LOW) {
      tft.drawString("Buzzer : OFF    ", 50, 80);
      analogWrite(WIO_BUZZER, 0);
      state = 0;
    }
    if (digitalRead(WIO_5S_LEFT) == LOW) {
      analogWrite(WIO_BUZZER, 0);
      tft.fillScreen(TFT_BLACK);
      mode = 0;
      toggle_buzzer = state;
      break;
    }
  }
}

void mode_Servo() {
  if (cntCursor == 2 && digitalRead(WIO_5S_PRESS) == LOW) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(3);
    tft.drawString("Servo : " + String(val) + String("    "), 50, 80);
    mode = 2;
    while (mode == 2) {
      if (digitalRead(WIO_5S_UP) == LOW) {
        val++;
        if (val > 180) val = 180;
        myservo.write(val);
        tft.drawString("Servo : " + String(val) + String("    "), 50, 80);
      }
      if (digitalRead(WIO_5S_DOWN) == LOW) {
        val--;
        if (val < 0) val = 0;
        myservo.write(val);
        tft.drawString("Servo : " + String(val) + String("    "), 50, 80);
      }
      if (digitalRead(WIO_5S_LEFT) == LOW) {
        tft.fillScreen(TFT_BLACK);
        mode = 0;
        break;
      }
    }
  }
}

void mode_DHT() {
  if (cntCursor == 3 && digitalRead(WIO_5S_PRESS) == LOW) {
    tft.fillScreen(TFT_BLACK);
    mode = 3;
    while (mode == 3) {
      tft.setTextSize(3);
      float temp = dht.readTemperature();
      float humi = dht.readHumidity();
      tft.drawString("Temp: " + String(temp) + String(" C "), 50, 80);
      tft.drawString("Humi: " + String(humi) + String(" %RH "), 50, 120);
      if (digitalRead(WIO_5S_LEFT) == LOW) {
        tft.fillScreen(TFT_BLACK);
        mode = 0;
        break;
      }
    }
  }
}
