#include <Ticker.h>
#define LED BCM0
Ticker blinker
void changeState() {
  digitalWrite(LED, !(digitalRead(LED)));  //Invert Current State of LED
}
void setup() {
  Serial.begin(115200);
  Serial.println("");
  pinMode(LED, OUTPUT);
  blinker.attach(0.5, changeState);  //Use attach_ms if you need time in ms
}

void loop() {
  // put your main code here, to run repeatedly:
}