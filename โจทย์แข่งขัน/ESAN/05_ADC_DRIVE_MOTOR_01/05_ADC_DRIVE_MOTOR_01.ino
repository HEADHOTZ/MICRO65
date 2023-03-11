#include"TFT_eSPI.h"
#include <SparkFun_TB6612.h>

#define AIN1 BCM2
#define BIN1 BCM0
#define AIN2 BCM3
#define BIN2 BCM1
#define PWMA BCM23
#define PWMB BCM27
#define STBY 9

TFT_eSPI tft;

const int offsetA = 1;
const int offsetB = 1;
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

int adcVal, adcMap, adcMap1, adcMap2;
byte adcPwmForward, adcPwmReward;

void setup() {
  // Serial.begin(9600);         // Innitail Serail Is 9600 B/S
  tft.begin();                // Innitail TFT LCD
  tft.setRotation(3);         //  Rotate Display On TFT LCD
  tft.setTextSize(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  delay(1000);
};

void loop() {
  // -----------  Read Analog  --------
  adcVal  = analogRead(A8);
  adcMap  = map(adcVal, 2, 1023, 0, 200);
  adcMap1 = map(adcMap, 100, 200, 0, 100); // Forward 0-100%
  adcMap2 = map(adcMap, 0, 100, 100, 0);   // Rerward 0-100%

  adcPwmForward = map(adcMap1, 0, 100, 0, 255);   // Forward
  adcPwmReward  = map(adcMap2, 100, 0, 255, 0);   // Rerward
  // Serial.println("Forward:"+String(adcPwmForward)+"   Reward:"+String(adcPwmReward));
  // tft.drawString(adcMap + String(" %   "), 115, 80);
  // ----------------   Condition Drive Mortor   -------------
  if (adcMap < 98) {  // adcMap<98 :Reverd
    tft.drawString(adcMap2 + String(" %   "), 115, 80); // Display 0-100%
    // ------- 100% Display REWARD -------
    if (adcMap2 == 100) {
      tft.drawString(" REWARD    ", 70, 120);
    }
    else {
      tft.drawString("                 ", 70, 120);
    }
    motor1.drive(-adcPwmReward);  // PWM:0-(-255)
    //motor2.drive(adcPwmReward);
  }
  else if (adcMap >= 98 and  adcMap <= 101) { // adcMap98-101 : Reverd
    tft.drawString(String(" 0%   "), 115, 80);
    tft.drawString("  STOP         ", 70, 120);

    motor1.brake();  // Motor Stop
    //motor2.brake();
  }
  else if (adcMap > 101) { // adcMap102-200 : Forward
    tft.drawString(adcMap1 + String(" %   "), 115, 80); // Display 0-100%
    // ------- 100% Display REWARD -------
    if (adcMap1 == 100)     tft.drawString(" FORWARD ", 70, 120);
    else                    tft.drawString("                 ", 70, 120);

    motor1.drive(adcPwmForward);    //PWM:0-255
    //motor2.drive(-adcPwmForward);
  }
  //----------------------------------------------------------
  delay(10);
};
