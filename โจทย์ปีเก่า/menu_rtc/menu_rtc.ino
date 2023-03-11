#include "TFT_eSPI.h"
#include "RTC_SAMD51.h"
#include "DateTime.h"
TFT_eSPI tft;
RTC_SAMD51 rtc;
DateTime now;

byte cntCursor = 1;
bool mode = 0;

byte h_antman_in = 0;
byte m_antman_in = 0;
byte h_antman_out = 0;
byte m_antman_out = 0;

byte h_ironman_in = 0;
byte m_ironman_in = 0;
byte h_ironman_out = 0;
byte m_ironman_out = 0;

byte h_spiderman_in = 0;
byte m_spiderman_in = 0;
byte h_spiderman_out = 0;
byte m_spiderman_out = 0;

byte h_superman_in = 0;
byte m_superman_in = 0;
byte h_superman_out = 0;
byte m_superman_out = 0;

byte digit1 = 0;
byte digit2 = 0;
byte digit3 = 0;
byte digit4 = 0;
void setup() {
  pinMode(WIO_5S_UP, INPUT_PULLUP);
  pinMode(WIO_5S_DOWN, INPUT_PULLUP);
  pinMode(WIO_5S_LEFT, INPUT_PULLUP);
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);

  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);

  rtc.begin();
  now = DateTime(F(__DATE__), F(__TIME__));
  //rtc.adjust(now);
}

void loop() {
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(3);
  Cursor();
  info_Antman();
  info_Ironman();
  info_Spiderman();
  info_Superman();
  real_Time();
}

void Cursor() {
  // ---------------  Cnt to Cursor  ------------
  if (digitalRead(WIO_5S_DOWN) == LOW) {
    while (digitalRead(WIO_5S_DOWN) == LOW) delay(10);
    Serial.println("5 Way Up");
    tft.fillScreen(TFT_BLACK);  // Clr Cursor
    cntCursor++;
    if (cntCursor >= 4) cntCursor = 4;
  } else if (digitalRead(WIO_5S_UP) == LOW) {
    while (digitalRead(WIO_5S_UP) == LOW) delay(10);
    Serial.println("5 Way Down");
    tft.fillScreen(TFT_BLACK);  // Clr Cursor
    cntCursor--;
    if (cntCursor <= 1) cntCursor = 1;
  }
  // ----------- Showe Cursor Of Position -------
  if (cntCursor == 1) {
    tft.drawString("> Ant Man", 50, 30);
    tft.drawString("  Iron Man", 50, 110);
    tft.drawString("  Spider Man", 50, 190);
  }
  if (cntCursor == 2) {
    tft.drawString("  Ant Man", 50, 30);
    tft.drawString("> Iron Man", 50, 110);
    tft.drawString("  Spider Man", 50, 190);
  }
  if (cntCursor == 3) {
    tft.drawString("  Ant Man", 50, 30);
    tft.drawString("  Iron Man", 50, 110);
    tft.drawString("> Spider Man", 50, 190);
  }
  if (cntCursor == 4) {
    tft.drawString("  Iron Man", 50, 30);
    tft.drawString("  Spider Man", 50, 110);
    tft.drawString("> Super Man", 50, 190);
  }
};
/* ------------------------------------------------------------------------ */

void info_Antman() {
  if (cntCursor == 1 && digitalRead(WIO_5S_RIGHT) == 0) {
    while (digitalRead(WIO_5S_RIGHT) == 0) delay(10);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(3);
    mode = 1;
    while (mode == 1) {
      char in[20];
      char out[20];
      now = rtc.now();
      int hour = now.hour();
      int min = now.minute();
      if (digitalRead(WIO_5S_RIGHT) == 0) {
        while (digitalRead(WIO_5S_RIGHT) == 0) delay(10);
        digit1++;
        if (digit1 == 1) {
          h_antman_in = now.hour();
          m_antman_in = now.minute();
        }
        if (digit1 == 2) {
          h_antman_out = now.hour();
          m_antman_out = now.minute();
        }
        if (digit1 == 2) digit1 = 0;
        Serial.println(digit1);
      }
      sprintf(in, " %02d:%02d", h_antman_in, m_antman_in);
      sprintf(out, " %02d:%02d", h_antman_out, m_antman_out);
      tft.drawString("  Ant Man", 50, 30);
      tft.drawString("in" + String(in) + String("   "), 100, 110);
      tft.drawString("out" + String(out) + String("   "), 100, 190);

      if (digitalRead(WIO_5S_LEFT) == LOW) {
        tft.fillScreen(TFT_BLACK);
        mode = 0;
        break;
      }
    }
  }
}

void info_Ironman() {
  if (cntCursor == 2 && digitalRead(WIO_5S_RIGHT) == 0) {
    while (digitalRead(WIO_5S_RIGHT) == 0) delay(10);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(3);
    mode = 1;
    while (mode == 1) {
      char in[20];
      char out[20];
      now = rtc.now();
      int hour = now.hour();
      int min = now.minute();
      if (digitalRead(WIO_5S_RIGHT) == 0) {
        while (digitalRead(WIO_5S_RIGHT) == 0) delay(10);
        digit2++;
        if (digit2 == 1) {
          h_ironman_in = now.hour();
          m_ironman_in = now.minute();
        }
        if (digit2 == 2) {
          h_ironman_out = now.hour();
          m_ironman_out = now.minute();
        }
        if (digit2 == 2) digit2 = 0;
        Serial.println(digit2);
      }
      sprintf(in, " %02d:%02d", h_ironman_in, m_ironman_in);
      sprintf(out, " %02d:%02d", h_ironman_out, m_ironman_out);
      tft.drawString("  Iron Man", 50, 30);
      tft.drawString("in" + String(in) + String("   "), 100, 110);
      tft.drawString("out" + String(out) + String("   "), 100, 190);

      if (digitalRead(WIO_5S_LEFT) == LOW) {
        tft.fillScreen(TFT_BLACK);
        mode = 0;
        break;
      }
    }
  }
}

void info_Spiderman() {
  if (cntCursor == 3 && digitalRead(WIO_5S_RIGHT) == 0) {
    while (digitalRead(WIO_5S_RIGHT) == 0) delay(10);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(3);
    mode = 1;
    while (mode == 1) {
      char in[20];
      char out[20];
      now = rtc.now();
      int hour = now.hour();
      int min = now.minute();
      if (digitalRead(WIO_5S_RIGHT) == 0) {
        while (digitalRead(WIO_5S_RIGHT) == 0) delay(10);
        digit3++;
        if (digit3 == 1) {
          h_spiderman_in = now.hour();
          m_spiderman_in = now.minute();
        }
        if (digit3 == 2) {
          h_spiderman_out = now.hour();
          m_spiderman_out = now.minute();
        }
        if (digit3 == 2) digit3 = 0;
        Serial.println(digit3);
      }
      sprintf(in, " %02d:%02d", h_spiderman_in, m_spiderman_in);
      sprintf(out, " %02d:%02d", h_spiderman_out, m_spiderman_out);
      tft.drawString("  Spider Man", 50, 30);
      tft.drawString("in" + String(in) + String("   "), 100, 110);
      tft.drawString("out" + String(out) + String("   "), 100, 190);

      if (digitalRead(WIO_5S_LEFT) == LOW) {
        tft.fillScreen(TFT_BLACK);
        mode = 0;
        break;
      }
    }
  }
}

void info_Superman() {
  if (cntCursor == 4 && digitalRead(WIO_5S_RIGHT) == 0) {
    while (digitalRead(WIO_5S_RIGHT) == 0) delay(10);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(3);
    mode = 1;
    while (mode == 1) {
      char in[20];
      char out[20];
      now = rtc.now();
      int hour = now.hour();
      int min = now.minute();
      if (digitalRead(WIO_5S_RIGHT) == 0) {
        while (digitalRead(WIO_5S_RIGHT) == 0) delay(10);
        digit4++;
        if (digit4 == 1) {
          h_superman_in = now.hour();
          m_superman_in = now.minute();
        }
        if (digit4 == 2) {
          h_superman_out = now.hour();
          m_superman_out = now.minute();
        }
        if (digit4 == 2) digit4 = 0;
        Serial.println(digit4);
      }
      sprintf(in, " %02d:%02d", h_superman_in, m_superman_in);
      sprintf(out, " %02d:%02d", h_superman_out, m_superman_out);
      tft.drawString("  Super Man", 50, 30);
      tft.drawString("in" + String(in) + String("   "), 100, 110);
      tft.drawString("out" + String(out) + String("   "), 100, 190);
      
      if (digitalRead(WIO_5S_LEFT) == LOW) {
        tft.fillScreen(TFT_BLACK);
        mode = 0;
        break;
      }
    }
  }
}

void real_Time() {
  char s[20];
  now = rtc.now();
  int day = now.day();
  int month = now.month();
  int year = now.year();
  //int year = now.year() + 543;
  int hour = now.hour();
  int min = now.minute();
  int sec = now.second();
  if (digitalRead(WIO_5S_PRESS) == 0) {
    while (digitalRead(WIO_5S_PRESS) == 0) delay(10);
    tft.fillScreen(TFT_BLACK);
    mode = 1;
  }
  while (mode == 1) {
    char s[20];
    now = rtc.now();
    int day = now.day();
    int month = now.month();
    int year = now.year();
    //int year = now.year() + 543;
    int hour = now.hour();
    int min = now.minute();
    int sec = now.second();
    tft.drawString("  Date/Time", 50, 30);
    sprintf(s, "  %02d:%02d:%02d", hour, min, sec);
    tft.drawString(s, 50, 110);
    sprintf(s, "  %02d/%02d/%d", day, month, year);
    tft.drawString(s, 50, 190);
    if (digitalRead(WIO_5S_PRESS) == 0) {
      while (digitalRead(WIO_5S_PRESS) == 0) delay(10);
      tft.fillScreen(TFT_BLACK);
      mode = 0;
      break;
    }
  }
}
