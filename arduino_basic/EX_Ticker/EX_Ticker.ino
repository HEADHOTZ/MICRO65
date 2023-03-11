#include <ESP8266WiFi.h>
#include <Ticker.h>  //Ticker Library

Ticker blinker;

#define LED D4  //On board LED
//=======================================================================
void changeState()
{
  digitalWrite(LED, !(digitalRead(LED)));  //Invert Current State of LED
}
void setup()
{
  Serial.begin(115200);
  Serial.println("");
  pinMode(LED, OUTPUT);

  //Initialize Ticker every 0.5s
  blinker.attach(0.5, changeState); //Use attach_ms if you need time in ms
}
void loop()
{
}
//=======================================================================
