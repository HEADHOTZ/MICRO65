#include <Servo.h>
#include <TFT_eSPI.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
TFT_eSPI tft;
Servo myservo;
#define SW1 BCM0
#define BUZZER_PIN WIO_BUZZER
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long currentMillis;
bool state = 0;

void setup() {
  mlx.begin();
  tft.begin();
  tft.setRotation(3);
  tft.setTextSize(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  myservo.attach(BCM9);
  Serial.begin(115200);
  myservo.write(90);
  delay(100);
  myservo.write(0);
  pinMode(SW1, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  float objTempC = mlx.readObjectTempC();
  currentMillis = millis();
  if (!digitalRead(SW1)) {
    while (!digitalRead(SW1)) delay(10);
    myservo.write(0);
    state = 0;
  }
  if (state == 0) {
    tft.fillScreen(TFT_BLACK);
    myservo.write(0);
  }
  if (state == 1) {
    myservo.write(90);
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.drawString(String(objTempC), 50, 150);
    oneBeep();
    Serial.println("Front hand");
  }
  if (objTempC < 30 && objTempC > 27) Serial.println("no obj");
  else if (objTempC > 30 && state == 0) {
    state = 1;
    //oneBeep();
  } else if (objTempC < 27) {
    tft.setTextColor(TFT_RED, TFT_BLACK);
    tft.drawString(String(objTempC), 50, 150);
    twoBeep();
    Serial.println("Back hand");
    delay(500);
    tft.fillScreen(TFT_BLACK);
    delay(500);
    state = 0;
  }
};

void oneBeep() {
  if ((currentMillis - previousMillis1) >= 500) {
    analogWrite(WIO_BUZZER, 128);
    delay(100);
    analogWrite(WIO_BUZZER, 0);
    previousMillis1 = millis();
  }
}

void twoBeep() {
  if ((currentMillis - previousMillis2) >= 500) {
    analogWrite(WIO_BUZZER, 128);
    delay(50);
    analogWrite(WIO_BUZZER, 0);
    delay(50);
    analogWrite(WIO_BUZZER, 128);
    delay(50);
    analogWrite(WIO_BUZZER, 0);
    previousMillis2 = millis();
  }
}