#include <TFT_eSPI.h>

#define IN1 BCM0
#define IN2 BCM1
#define PWM BCM27
#define SW1 BCM2
#define SW2 BCM3
#define SW3 BCM4
#define SW4 BCM5
#define VR A1

TFT_eSPI tft;

bool forward_state = 0;
bool forward_mem = 0;
bool reverse_state = 0;
bool reverse_mem = 0;
bool stop_state = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
  pinMode(VR, INPUT);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(3);
  tft.drawString("Stop", 120, 90);
  Serial.begin(115200);
}

void loop() {
  int valADC = map(analogRead(VR), 2, 1023, 0, 100);
  int get = map(valADC, 0, 100, 0, 255);
  int value = map(get, 0, 255, 0, 100);
  tft.setTextSize(4);
  tft.drawString("Motor Control", 0, 20);
  tft.setTextSize(3);
  tft.drawString("Set", 30, 150);
  tft.drawString("Speed", 230, 150);
  tft.drawString(String(valADC) + String("   "), 30, 200);

  if (!digitalRead(SW1)) {
    while (!digitalRead(SW1)) delay(10);
    stop_state = 0;
    tft.drawString("Forward" + String("   "), 100, 90);
    if (reverse_state == 1) {
      for (int i = value; i >= 0; i--) {
        int speed = map(i, 0, 100, 0, 255);
        digitalWrite(IN1, 0);
        digitalWrite(IN2, 1);
        analogWrite(PWM, speed);
        tft.drawString(String(i) + String("   "), 230, 200);
        if (i == 0) reverse_state = 0;
        delay(100);
      }
    }
    for (int i = 0; i <= value; i++) {
      int speed = map(i, 0, 100, 0, 255);
      digitalWrite(IN1, 1);
      digitalWrite(IN2, 0);
      analogWrite(PWM, speed);
      tft.drawString(String(i) + String("   "), 230, 200);
      delay(100);
    }
    forward_state = 1;
    forward_mem = 1;
    reverse_mem = 0;
  }

  if (!digitalRead(SW2)) {
    while (!digitalRead(SW2)) delay(10);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(4);
    tft.drawString("Motor Control", 0, 20);
    tft.setTextSize(3);
    tft.drawString("Set", 30, 150);
    tft.drawString("Speed", 230, 150);
    tft.drawString(String(valADC) + String("   "), 30, 200);
    tft.drawString("Stop", 120, 90);
    stop_state = 1;
    if (forward_state == 1) {
      for (int i = value; i >= 0; i--) {
        int speed = map(i, 0, 100, 0, 255);
        digitalWrite(IN1, 1);
        digitalWrite(IN2, 0);
        analogWrite(PWM, speed);
        tft.drawString(String(i) + String("   "), 230, 200);
        if (i == 0) forward_state = 0;
        delay(100);
      }
    }
    if (reverse_state == 1) {
      for (int i = value; i >= 0; i--) {
        int speed = map(i, 0, 100, 0, 255);
        digitalWrite(IN1, 0);
        digitalWrite(IN2, 1);
        analogWrite(PWM, speed);
        tft.drawString(String(i) + String("   "), 230, 200);
        if (i == 0) reverse_state = 0;
        delay(100);
      }
    }
  }

  if (!digitalRead(SW3)) {
    while (!digitalRead(SW3)) delay(10);
    stop_state = 0;
    tft.drawString("Reverse" + String("   "), 100, 90);
    if (forward_state == 1) {
      for (int i = value; i >= 0; i--) {
        int speed = map(i, 0, 100, 0, 255);
        digitalWrite(IN1, 1);
        digitalWrite(IN2, 0);
        analogWrite(PWM, speed);
        tft.drawString(String(i) + String("   "), 230, 200);
        if (i == 0) forward_state = 0;
        delay(100);
      }
    }
    for (int i = 0; i <= value; i++) {
      int speed = map(i, 0, 100, 0, 255);
      digitalWrite(IN1, 0);
      digitalWrite(IN2, 1);
      analogWrite(PWM, speed);
      tft.drawString(String(i) + String("   "), 230, 200);
      delay(100);
    }
    reverse_state = 1;
    reverse_mem = 1;
    forward_mem = 0;
  }

  if (!digitalRead(SW4)) {
    while (!digitalRead(SW4)) delay(10);
    reverse_state = 0;
    forward_state = 0;
    if (stop_state == 0) {
      tft.fillScreen(TFT_BLACK);
      tft.drawString("Stop", 120, 90);
      digitalWrite(IN1, 1);
      digitalWrite(IN2, 1);
      analogWrite(PWM, 0);
      stop_state = 1;
    } else if (stop_state == 1) {
      if (forward_mem == 1) {
        tft.drawString("Forward" + String("   "), 100, 90);
        for (int i = 0; i <= value; i++) {
          int speed = map(i, 0, 100, 0, 255);
          digitalWrite(IN1, 1);
          digitalWrite(IN2, 0);
          analogWrite(PWM, speed);
          tft.drawString(String(i) + String("   "), 230, 200);
          delay(100);
        }
        forward_state = 1;
        forward_mem = 1;
        reverse_mem = 0;
        stop_state = 0;
      } else if (reverse_mem == 1) {
        tft.drawString("Reverse" + String("   "), 100, 90);
        for (int i = 0; i <= value; i++) {
          int speed = map(i, 0, 100, 0, 255);
          digitalWrite(IN1, 0);
          digitalWrite(IN2, 1);
          analogWrite(PWM, speed);
          tft.drawString(String(i) + String("   "), 230, 200);
          delay(100);
        }
        reverse_state = 1;
        forward_mem = 0;
        reverse_mem = 1;
      }
      stop_state = 0;
    }
  }

  Serial.println("stop : " + String(stop_state));
};