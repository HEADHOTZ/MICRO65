#include <TFT_eSPI.h>
#define VR A1
#define SW BCM0
#define IN1 BCM2
#define IN2 BCM3
#define PWM BCM27
TFT_eSPI tft;
bool state = 0;
unsigned long previousMillis1 = 0;

void setup() {
  pinMode(VR, INPUT);
  pinMode(SW, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM, OUTPUT);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(4);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();
  int val = map(analogRead(VR), 2, 1023, 0, 200);
  int left_val = map(val, 0, 99, 100, 1);
  int right_val = map(val, 101, 200, 1, 100);
  int pwm_left = map(left_val, 1, 100, 0, 255);
  int pwm_right = map(val, 101, 200, 0, 255);

  if (!digitalRead(SW)) {
    while (!digitalRead(SW)) delay(10);
    state = !state;
  }
  if ((currentMillis - previousMillis1) >= 200) {
    if (val >= 95 || val <= 105 && state == 1) {
      Serial.println("0");
      tft.drawString("          ", 100, 100);
      tft.drawString("          ", 100, 150);
      tft.drawString("STOP", 100, 100);
    }
    if (val < 95 && state != 1) {
      Serial.println("Left : " + String(pwm_left));
      tft.drawString("          ", 100, 100);
      tft.drawString("BACKWARD", 100, 100);
      tft.drawString("          ", 100, 150);
      tft.drawNumber(left_val, 100, 150);
    }
    if (val > 105 && state != 1) {
      Serial.println("Right : " + String(pwm_right));
      tft.drawString("          ", 100, 100);
      tft.drawString("FORWARD", 100, 100);
      tft.drawString("          ", 100, 150);
      tft.drawNumber(right_val, 100, 150);
    }
    previousMillis1 = millis();  // save the "current" time
  }


  if (val >= 95 || val <= 105 && state == 1) {
    /*Serial.println("0");
    tft.drawString("          ", 100, 100);
    tft.drawString("          ", 100, 150);
    tft.drawString("STOP", 100, 100);*/
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 1);
    analogWrite(PWM, 0);
  }
  if (val < 95 && state != 1) {
    /*Serial.println("Left : " + String(pwm_left));
    tft.drawString("          ", 100, 100);
    tft.drawString("BACKWARD", 100, 100);
    tft.drawString("          ", 100, 150);
    tft.drawNumber(left_val, 100, 150);*/
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    analogWrite(PWM, pwm_left);
  }
  if (val > 105 && state != 1) {
    /*Serial.println("Right : " + String(pwm_right));
    tft.drawString("          ", 100, 100);
    tft.drawString("FORWARD", 100, 100);
    tft.drawString("          ", 100, 150);
    tft.drawNumber(right_val, 100, 150);*/
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    analogWrite(PWM, pwm_right);
  }
}