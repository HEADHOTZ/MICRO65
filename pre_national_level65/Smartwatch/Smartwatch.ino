#include "RTC_SAMD51.h"
#include "DateTime.h"
#include <DFRobot_MAX30102.h>
#include "seeed_line_chart.h"  //include the library

DFRobot_MAX30102 particleSensor;
TFT_eSPI tft;
RTC_SAMD51 rtc;
DateTime now;
byte mode = 0;

int32_t SPO2;
int8_t SPO2Valid;
int32_t heartRate;
int8_t heartRateValid;
int heart;
int oxygen;

unsigned long previousMillis1 = 0;

doubles data_read[3];  //    must use only doubles to 2 line graph
int last_val = 0;

int max_size = 50;                    //maximum size of data
TFT_eSprite spr = TFT_eSprite(&tft);  // Sprite

void setup() {
  spr.createSprite(TFT_HEIGHT, TFT_WIDTH);
  spr.setRotation(3);

  pinMode(A0, INPUT);
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);

  rtc.begin();
  now = DateTime(F(__DATE__), F(__TIME__));
  rtc.adjust(now);

  while (!particleSensor.begin()) {
    tft.drawString("MAX30102 Fail !.", 50, 120);
    delay(1000);
  }
  particleSensor.sensorConfiguration(/*ledBrightness=*/60, /*sampleAverage=*/SAMPLEAVG_4,
                                     /*ledMode=*/MODE_MULTILED, /*sampleRate=*/SAMPLERATE_1000,
                                     /*pulseWidth=*/PULSEWIDTH_411, /*adcRange=*/ADCRANGE_16384);
}

void loop() {
  if (digitalRead(WIO_5S_PRESS) == LOW) {
    while (digitalRead(WIO_5S_PRESS) == LOW) delay(10);
    mode += 1;
    if (mode > 2) mode = 0;
    tft.fillScreen(TFT_BLACK);
  }
  if (mode == 0) {
    char i[20];
    now = rtc.now();
    int hour = now.hour();
    int min = now.minute();
    int day = now.day();
    char month = now.month();
    int year = now.year();
    int val = map(analogRead(A0), 0, 1023, 0, 100);
    int rect = map(val, 0, 100, 0, 150);
    int rect_back = map(val, 100, 0, 150, 0);
    tft.setTextSize(3);
    sprintf(i, " %02d.%02d", hour, min);
    tft.drawString(i, 90, 50);
    switch (month) {
      case 1:
        sprintf(i, "%02d Jan %02d", day, year);
        break;
    }
    tft.drawString(i, 60, 100);
    tft.drawString("Power " + String(val) + String("%" + String("   ")), 80, 150);
    tft.drawRoundRect(80, 200, 150, 25, 10, TFT_WHITE);
    tft.fillRoundRect(80, 200, rect, 25, 10, TFT_WHITE);
    if (last_val != val) {
      tft.fillScreen(TFT_BLACK);
      last_val = val;
    }
    Serial.println(val);
  }
  if (mode == 1) {
    if (particleSensor.getIR() > 45000)
      particleSensor.heartrateAndOxygenSaturation(&SPO2, &SPO2Valid, &heartRate, &heartRateValid);
    spr.fillSprite(TFT_WHITE);
    if (heartRate != -999) heart = heartRate;
    if (SPO2 != -999) oxygen = SPO2;
    //Settings for the line graph title
    if (data_read[0].size() == max_size) {
      for (uint8_t i = 0; i < 3; i++) {
        data_read[i].pop();  //this is used to remove the first read variable
      }
    }
    data_read[0].push(heart);
    data_read[1].push(oxygen);
    auto header = text(0, 0)
                    .value("Heart rate")
                    .align(center)
                    .valign(vcenter)
                    .width(spr.width())
                    .thickness(3);
    header.height(header.font_height(&spr) * 2);
    header.draw(&spr);  // Header height is the twice the height of the font

    //Settings for the line graph
    auto content = line_chart(20, header.height());  //(x,y) where the line graph begins
    content
      .height(spr.height() - header.height() * 1.5)  //actual height of the line chart
      .width(spr.width() - content.x() * 2)          //actual width of the line chart
      .based_on(0.0)                                 //Starting point of y-axis, must be a float
      .show_circle(false)                            //drawing a cirle at each point, default is on.
      //.value({accelerator_readings[0],accelerator_readings[1], accelerator_readings[2]}) //passing through the data to line graph
      .value({ data_read[0], data_read[1] })  //passing through the data to line graph
      .max_size(max_size)
      .color(TFT_RED, TFT_BLUE)
      .backgroud(TFT_WHITE)
      .draw(&spr);
    spr.pushSprite(0, 0);
    Serial.println(heart);
    Serial.println(oxygen);
  }  //  End Mode  1
  if (mode == 2) {
    if (particleSensor.getIR() > 45000)
      particleSensor.heartrateAndOxygenSaturation(&SPO2, &SPO2Valid, &heartRate, &heartRateValid);
    if (SPO2 != -999) oxygen = SPO2;
    tft.drawString(String(oxygen) + String(" %"), 150, 100);
  }
}
