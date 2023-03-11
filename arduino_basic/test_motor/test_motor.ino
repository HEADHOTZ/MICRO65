#include <TFT_eSPI.h>
TFT_eSPI tft;
#define IN1 BCM2
#define IN2 BCM3
#define PWM BCM27

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM, OUTPUT);
  tft.begin();
  tft.fillScreen(TFT_BLACK);
  tft.setRotation(3);
  tft.setTextSize(2);
  Serial.begin(115200);
}

void loop() {
  //Clock Wise
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  analogWrite(PWM, 127);
  delay(1000);

  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);
  analogWrite(PWM, 0);
  delay(1000);
  //counter clockwise
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  analogWrite(PWM, 127);
  delay(1000);

  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);
  analogWrite(PWM, 0);
  delay(1000);
}