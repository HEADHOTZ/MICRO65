//#include <M5Stack.h>
/* ------------------------------------------------------------------------ */
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Input Your String : ");
};

void loop() {
  if(Serial.available() > 0){
    String str = Serial.readStringUntil('\n');
    Serial.print(str);
    Serial.print(" = ");
    Serial.println(str.substring(0, 2));
    // -----------------------------
    if(str.substring(0, 1) == "ry"){
      Serial.println("Relay 1 Is ON");
    }
    if(str.substring(0, 3) == "rgb"){
      Serial.println("RGB Is 1");
    }
   // ------------------------------ 
  }
  delay(100);
};
/* ------------------------------------------------------------------ */
