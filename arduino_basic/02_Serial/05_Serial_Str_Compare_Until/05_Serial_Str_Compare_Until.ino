#include <M5Stack.h>

String str = "";
/* ------------------------------------------------------------------------ */
void setup() {
  Serial.begin(115200);
  pinMode(17, OUTPUT);
  Serial.println();
  Serial.println("Input Your String : ");
};

void loop() {
  if(Serial.available() > 0){
     str = Serial.readStringUntil('\n');
     Serial.println(str);
    // -----------------------------
    if(str == "on_ry1" || str == "ON_RY1"){
      Serial.println("Relay Is ON");
      digitalWrite(17,1);
    }
    if(str == "off_ry1"){
      Serial.println("Relay Is OFF");
      digitalWrite(17,0);
    }
   // ------------------------------ 
  } // Serial Available
  delay(10);
};
/* ------------------------------------------------------------------ */
