#include <PCA9685.h>
#include <TFT_eSPI.h>
TFT_eSPI tft;
PCA9685 pwmController;

PCA9685_ServoEval pwmServo;

void setup() {
  Wire.begin();
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("M-SERVO", 120, 20);
  tft.drawString("Servo Controller", 60, 40);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  pwmController.resetDevices();
  pwmController.init();
  pwmController.setPWMFrequency(50);
}

void loop() {

  pwmController.setChannelPWM(1, pwmServo.pwmForAngle(-90));
  delay(500);
  pwmController.setChannelPWM(1, pwmServo.pwmForAngle(-45));
  delay(500);
  pwmController.setChannelPWM(1, pwmServo.pwmForAngle(0));
  delay(500);
    pwmController.setChannelPWM(1, pwmServo.pwmForAngle(45));
  delay(500);
  pwmController.setChannelPWM(1, pwmServo.pwmForAngle(90));
  delay(500);
}