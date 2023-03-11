#include <TFT_eSPI.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_PWMServoDriver.h>

TFT_eSPI tft;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
//-------------  Servo  -----------
Adafruit_PWMServoDriver Pwm = Adafruit_PWMServoDriver();
#define SERVO_FREQ 50

boolean stBeeb = 1;
//------------------------------------------------------------- //
void setup() {
  pinMode(WIO_BUZZER, OUTPUT);
  pinMode(WIO_BUZZER, OUTPUT);

  tft.begin();
  mlx.begin();
  //-------------  Servo  -----------
  Pwm.begin();
  Pwm.setOscillatorFrequency(27000000);
  Pwm.setPWMFreq(SERVO_FREQ);

  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK); //Black background
  tft.setTextColor(TFT_WHITE, TFT_BLACK);     // Clear Display Anty Font Replace :  Fill Coler ,Font Color
  tft.setTextSize(3);
  tft.drawString("IR-TEMP,SERVO ", 30, 10);

  Pwm.setPWM(0, 0, 280);
  delay(1000);
};
//------------------------------------------------------------- //
void loop() {
  //----------------------------------------------
  float ambTempC = mlx.readAmbientTempC();
  float objTempC = mlx.readObjectTempC();
  // ---------------  Font Hand  -----------------
  if (objTempC > 33) {
    tft.setTextColor(TFT_GREEN, TFT_BLACK);    // Chang Text To Green
    tft.drawString(String("Object: ") + String(objTempC) + String(" C   "), 15, 120);
    if (stBeeb == 1) {                         // One Beeb
      Pwm.setPWM(0, 0, 20);
      analogWrite(WIO_BUZZER, 50);
      delay(300);
      analogWrite(WIO_BUZZER, 0);
      stBeeb = 0;
      delay(500);
    }
  }
  else {
   // Pwm.setPWM(0, 0, 280);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    stBeeb = 1;
    delay(1000);
  }
  // ---------------  Back Hand  -----------------
   
  // ---------------------------------------------
  tft.drawString(String("Object: ") + String(objTempC) + String(" C   "), 15, 120);
};
//------------------------------------------------------------- //
