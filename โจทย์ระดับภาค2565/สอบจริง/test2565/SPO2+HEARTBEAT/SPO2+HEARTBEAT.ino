#include <TFT_eSPI.h>
#include <Wire.h>
#include <DFRobot_MAX30102.h>
#include <Adafruit_MLX90614.h>
#define BUZZER_PIN WIO_BUZZER
TFT_eSPI tft;
DFRobot_MAX30102 particleSensor;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

int32_t SPO2;
int8_t SPO2Valid;
int32_t heartRate;
int8_t heartRateValid;
unsigned long previousMillis1 = 0;
bool stbeep = 0;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  tft.begin();
  mlx.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  while (!particleSensor.begin()) {
    tft.drawString("MAX30102 Fail !.", 50, 120);
    delay(1000);
  }
  particleSensor.sensorConfiguration(/*ledBrightness=*/60, /*sampleAverage=*/SAMPLEAVG_4,
                                     /*ledMode=*/MODE_MULTILED, /*sampleRate=*/SAMPLERATE_100,
                                     /*pulseWidth=*/PULSEWIDTH_411, /*adcRange=*/ADCRANGE_16384);
}

void loop() {
  float objTempC = mlx.readObjectTempC();
  unsigned long currentMillis = millis();

  if (particleSensor.getIR() > 50000) {
    if (stbeep == 1) {
      analogWrite(WIO_BUZZER, 50);
      delay(200);
      analogWrite(WIO_BUZZER, 0);
      delay(200);
      stbeep = 0;
    }
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.drawString("      ", 120, 120);
    tft.setTextSize(4);
    tft.drawString("HEART BEAT", 50, 10);
    tft.setTextSize(2);
    tft.drawString("HEART BEAT", 30, 100);
    tft.drawString("SPO2", 230, 100);
    if (heartRateValid == 1 && SPO2Valid == 1) {
      tft.drawString("               ", 50, 150);
      tft.drawString(String(heartRate), 50, 150);
      tft.drawString("          ", 230, 150);
      tft.drawString(String(SPO2), 230, 150);
    } else {
      tft.drawString("               ", 50, 150);
      tft.drawString("          ", 230, 150);
    }

    if ((currentMillis - previousMillis1) >= 4000) {
      particleSensor.heartrateAndOxygenSaturation(&SPO2, &SPO2Valid, &heartRate, &heartRateValid);
      previousMillis1 = millis();
    }
  }

  else if (objTempC >= 31) {
    if (stbeep == 1) {
      analogWrite(WIO_BUZZER, 50);
      delay(200);
      analogWrite(WIO_BUZZER, 0);
      delay(200);
      stbeep = 0;
    }
    tft.drawString("      ", 120, 120);
    tft.setTextSize(2);
    tft.drawString("Infrared Thermometer", 30, 50);
    tft.setTextSize(3);
    tft.drawString(String(objTempC), 130, 130);
    tft.setTextSize(1);
  }

  else {
    tft.setTextSize(4);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.drawString("---  ", 120, 120);
    tft.drawString("                     ", 50, 10);
    tft.drawString("                     ", 30, 100);
    tft.drawString("                     ", 230, 100);
    tft.drawString("                     ", 50, 150);
    tft.drawString("                     ", 230, 150);
    tft.drawString("                     ", 50, 50);
    tft.drawString("                      ", 30, 50);
    //tft.drawString("            ", 130, 130);
    stbeep = 1;
  }
  Serial.println("heartRateValid: " + String(heartRateValid));
  Serial.println("SPO2Valid: " + String(SPO2Valid));
  Serial.println(objTempC);
  Serial.println(String(particleSensor.getIR()));
};
