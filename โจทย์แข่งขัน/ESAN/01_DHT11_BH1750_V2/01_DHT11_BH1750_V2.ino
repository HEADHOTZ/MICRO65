/* ******************************************************************************* */
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
  tft.drawString("Temperature", 10, 10);
  tft.drawString("Humidity", 195, 10);
  tft.drawString("Light", 130, 140);

  tft.drawRoundRect(3,3,165,80,5,TFT_WHITE);       // x,y,w,h : Temp
  tft.drawRoundRect(171,3,145,80,5,TFT_WHITE);     // x,y,w,h : Hum
  tft.drawRoundRect(10,120,300,110,5,TFT_WHITE);    // x,y,w,h : Light
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
  tft.drawString(String(t)+"  C", 35, 50);         // Show Temp,
  tft.drawCircle(98,52,3,TFT_WHITE);
  tft.drawString(String(h)+" %", 210, 50);         // Show Humidty
  // -----------        Show Light BH1750     ------------  //
  float lux = lightMeter.readLightLevel();
  tft.drawString(String(lux)+" lux", 100, 180);         // Show Temp
  
  delay(250);
};
/* ******************************************************************************* */
