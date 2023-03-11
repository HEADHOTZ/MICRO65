#include"TFT_eSPI.h"
#include"Free_Fonts.h" //include the header file
#include "DHT.h"
#include <Wire.h>
#include <BH1750.h>

TFT_eSPI tft;

#define DHTPIN D2
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

BH1750 lightMeter;
/* ******************************************************************************* */
void setup() {
 // Serial.begin(9600);         // Innitail Serail Is 9600 B/S
  
  tft.begin();                // Innitail TFT LCD
  tft.setRotation(3);         //  Rotate Display On TFT LCD
  tft.fillScreen(TFT_BLUE);   //BLUE background

  dht.begin();               // Innitial DHT11            
  Wire.begin();              // Innitial I2C Bus  
  lightMeter.begin();        // Innitial BH1750
  // -----------  Display Text On Start  --------
  tft.setFreeFont(FSSBO12);                     //select Free, Sans, Bold, Oblique, 12pt
  tft.setTextColor(TFT_WHITE);                 //sets the text colour to WHITE
  tft.drawString("Temperature", 0, 10);
  tft.drawString("Humidity", 205, 10);
  tft.drawString("Light", 130, 120);
};
/* ******************************************************************************* */
void loop() {
  // --------------  Read Temp,Humidity DHT11 ------------- //
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
 // Serial.println("Temp:" + String(t));
 // Serial.println("Humid:" + String(h));
 
  // -----------  Show Temp,Humidity On TFT LCD  ----------- //
  tft.setFreeFont(FS12);                     //select Free, Sans, Bold, Oblique, 12pt
  tft.setTextColor(TFT_WHITE, TFT_BLUE);     // Clear Display Anty Font Replace :  Fill Coler ,Font Color 
  tft.drawString(String(t)+" C", 30, 50);         // Show Temp
  tft.drawString(String(h)+" %", 210, 50);         // Show Humidty
  // -----------        Show Light BH1750     ------------  //
 // tft.setTextColor(TFT_WHITE, TFT_BLUE);     // Clear Display Anty Font Replace :  Fill Coler ,Font Color 
  float lux = lightMeter.readLightLevel();
  tft.drawString(String(lux)+" Lux", 100, 160);         // Show Temp
  
  delay(250);
};
/* ******************************************************************************* */
