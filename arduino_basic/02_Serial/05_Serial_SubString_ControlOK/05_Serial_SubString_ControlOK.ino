#include <M5Stack.h>

#define ry1 17
#define ry2 16
/* ------------------------------------------------------------------------ */
void setup() {
  Serial.begin(115200);
  pinMode(ry1, OUTPUT);
  pinMode(ry2, OUTPUT);
  Serial.println();
  Serial.println("Input Your String : ");
};

void loop() {
  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('\n');
    Serial.print(str);
    Serial.print(" = ");
    Serial.println(str.substring(2, 3));
    // -----------------------------
    if (str.substring(0, 2) == "ry") {   // ry
      if (str.substring(2, 3) == "1") {
        digitalWrite(ry1, 1);
        Serial.println("Relay 1 Is ON");
      }
      if (str.substring(2,3) == "2") {
        digitalWrite(ry2, 1);
        Serial.println("Relay 2 Is ON");
      }
    } //Relay
    
    if (str.substring(0, 3) == "rgb") {  // RGB
      if (str.substring(3, 4) == "1") {
        Serial.println("RGB Is 1");
      }
      if (str.substring(3, 4) == "2") {
        Serial.println("RGB Is 2");
      }
    } // RGB
    // ------------------------------
  }
  delay(100);
};
/* ------------------------------------------------------------------ */
