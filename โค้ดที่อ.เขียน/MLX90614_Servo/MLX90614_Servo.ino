#include <TFT_eSPI.h>
#include"Free_Fonts.h" 
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Servo.h>
#define SW1 4
TFT_eSPI tft;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
Servo myservo;
bool stBeep = 1;

void setup() {
  Serial.begin(115200);
  pinMode(WIO_BUZZER, OUTPUT);
  pinMode(SW1, INPUT);
  myservo.write(0);
  delay(250);
  tft.begin();
  mlx.begin();
  myservo.attach(8);
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK); 
  tft.setTextColor(TFT_WHITE, TFT_BLACK);     
  tft.setTextSize(2);
  tft.drawString("Infrared Thermometer ", 30, 80);
}

void loop() {
  float objTempC = mlx.readObjectTempC();
  Serial.println(objTempC);
  delay(50); 
  // ---------------  Font Hand  -----------------
  if(objTempC > 28.1) {
    tft.setFreeFont(FS12);
    tft.setTextColor(TFT_GREEN, TFT_BLACK);    
    tft.drawString(String(objTempC) + String("     "), 100, 120);
    delay(500);
    if (stBeep == 1) {                         // One Beeb
      myservo.write(90);
      analogWrite(WIO_BUZZER, 50);
      delay(200);
      analogWrite(WIO_BUZZER, 0);
      delay(200);
      stBeep = 0;
    }
  }
 
  // ---------------  Back Hand  -----------------
  else if(objTempC > 27.5) {
    tft.setFreeFont(FS12);
    tft.setTextColor(TFT_RED, TFT_BLACK);    
    tft.drawString(String(objTempC) + String("     "), 100, 120);
    delay(500);
    if (stBeep == 1) {                         // Two Beeb
      myservo.write(0);
      analogWrite(WIO_BUZZER, 50);
      delay(200);
      analogWrite(WIO_BUZZER, 0);
      delay(200);
      analogWrite(WIO_BUZZER, 50);
      delay(200);
      analogWrite(WIO_BUZZER, 0);
      delay(200);
      stBeep = 0;
    }
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.drawString(String("                 "), 50, 120);
    delay(500);
    stBeep = 1;
  }
  else {
    stBeep = 1;
  }
  // ---------------  Push SW  -----------------
  if(!digitalRead(SW1)) {
    while(digitalRead(SW1)==0) delay(10);
    Serial.println(digitalRead(SW1));
    myservo.write(0);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.drawString(String("                 "), 50, 120);
  }
}
