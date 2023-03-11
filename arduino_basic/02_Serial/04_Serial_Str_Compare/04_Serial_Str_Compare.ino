#include <M5Stack.h>

String readString;
/* ------------------------------------------------------------------- */
void setup() {
  pinMode(17, OUTPUT);
  Serial.begin(115200);
}
/* ------------------------------------------------------------------- */
void loop() {
  if (Serial.available()) {
    String ch;
    ch = Serial.readString();
    ch.trim();
    Serial.print("RELAY IS : ");
    Serial.println(ch);
    // --------------------------------
    if (ch == "on" || ch == "ON") {
      digitalWrite(17, HIGH);
    }
    if (ch == "off" or ch == "OFF") {
      digitalWrite(17, LOW);
    }
    //--------------------------------
  }// Serial available
};
/* ------------------------------------------------------------------- */
