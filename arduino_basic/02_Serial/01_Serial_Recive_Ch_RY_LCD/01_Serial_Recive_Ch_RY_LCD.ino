/* --------------------------------------------------------------------------
   Recive Character To ON/OFF Relay(Togle)
   - GPIO 23,18 Not Use
*/
#include <M5Stack.h>

#define ry1 17
#define ry2 16
#define ry3 19
#define ry4 2
#define ry5 5
#define ry6 12
#define ry7 13
#define ry8 15


boolean stRy1 = 0;   boolean stRy2 = 0;
boolean stRy3 = 0;   boolean stRy4 = 0;
boolean stRy5 = 0;   boolean stRy6 = 0;
boolean stRy7 = 0;   boolean stRy8 = 0;
/* -------------------------------------------------------------------------- */
void setup() {
  M5.begin();
  Serial.begin(115200);
  // Set Direction Port I/O
  pinMode(ry1, OUTPUT);   pinMode(ry2, OUTPUT);
  pinMode(ry3, OUTPUT);   pinMode(ry4, OUTPUT);
  pinMode(ry5, OUTPUT);   pinMode(ry6, OUTPUT);
  pinMode(ry7, OUTPUT);   pinMode(ry8, OUTPUT);

  M5.Lcd.setCursor(0, 10, 4);
  M5.Lcd.println("RERAY1 : OFF");
  M5.Lcd.println("RERAY2 : OFF");
  M5.Lcd.println("RERAY3 : OFF");
  M5.Lcd.println("RERAY4 : OFF");
  M5.Lcd.println("RERAY5 : OFF");
  M5.Lcd.println("RERAY6 : OFF");
  M5.Lcd.println("RERAY7 : OFF");
  M5.Lcd.println("RERAY8 : OFF");
};
/* -------------------------------------------------------------------------- */
void loop() {
  if (Serial.available()) {
    int ch = Serial.read();
    Serial.write(ch);
    /* ---------------------------   Condition Relay ON/OFF   -------------------------- */
    switch (ch) {
      case 'a':
        stRy1 = !stRy1;
        digitalWrite(ry1, stRy1); delay(100);
        if (stRy1 == 1) {
          M5.Lcd.setCursor(0, 10, 4); M5.Lcd.print("RERAY1 : ON   ");
        }
        if (stRy1 == 0) {
          M5.Lcd.setCursor(0, 10, 4); M5.Lcd.print("RERAY1 : OFF");
        }
        break;
      case 'b':
        stRy2 = !stRy2;
        digitalWrite(ry2, stRy2); delay(100);
        if (stRy2 == 1) {
          M5.Lcd.setCursor(0, 36, 4); M5.Lcd.print("RERAY2 : ON   ");
        }
        if (stRy2 == 0) {
          M5.Lcd.setCursor(0, 36, 4); M5.Lcd.print("RERAY2 : OFF");
        }
        break;
      case 'c':
        stRy3 = !stRy3;
        digitalWrite(ry3, stRy3); delay(100);
        if (stRy3 == 1) {
          M5.Lcd.setCursor(0, 62, 4); M5.Lcd.print("RERAY3 : ON   ");
        }
        if (stRy3 == 0) {
          M5.Lcd.setCursor(0, 62, 4); M5.Lcd.print("RERAY3 : OFF");
        }
        break;
      case 'd':
        stRy4 = !stRy4;
        digitalWrite(ry4, stRy4); delay(100);
        if (stRy4 == 1) {
          M5.Lcd.setCursor(0, 88, 4); M5.Lcd.print("RERAY4 : ON   ");
        }
        if (stRy4 == 0) {
          M5.Lcd.setCursor(0, 88, 4); M5.Lcd.print("RERAY4 : OFF");
        }
        break;
      case 'e':
        stRy5 = !stRy5;
        digitalWrite(ry5, stRy5); delay(100);
        if (stRy5 == 1) {
          M5.Lcd.setCursor(0, 114, 4); M5.Lcd.print("RERAY5 : ON   ");
        }
        if (stRy5 == 0) {
          M5.Lcd.setCursor(0, 114, 4); M5.Lcd.print("RERAY5 : OFF");
        }
        break;
      case 'f':
        stRy6 = !stRy6;
        digitalWrite(ry6, stRy6); delay(100);
        if (stRy6 == 1) {
          M5.Lcd.setCursor(0, 140, 4); M5.Lcd.printf("RERAY6 : ON   ");
        }
        if (stRy6 == 0) {
          M5.Lcd.setCursor(0, 140, 4); M5.Lcd.printf("RERAY6 : OFF");
        }
        break;
      case 'i':
        stRy7 = !stRy7;
        digitalWrite(ry7, stRy7); delay(100);
        if (stRy7 == 1) {
          M5.Lcd.setCursor(0, 166, 4); M5.Lcd.printf("RERAY7 : ON   ");
        }
        if (stRy7 == 0) {
          M5.Lcd.setCursor(0, 166, 4); M5.Lcd.printf("RERAY7 : OFF");
        }
        break;
      case 'j':
        stRy8 = !stRy8;
        digitalWrite(ry8, stRy8); delay(100);
        if (stRy8 == 1) {
          M5.Lcd.setCursor(0, 192, 4); M5.Lcd.printf("RERAY8 : ON   ");
        }
        if (stRy8 == 0) {
          M5.Lcd.setCursor(0, 192, 4); M5.Lcd.printf("RERAY8 : OFF");
        }
        break;
      case 'k':
        // ------  Condition OFF Al Relay 1-8   ------- //
          digitalWrite(ry1, 0); digitalWrite(ry2, 0);
          digitalWrite(ry3, 0); digitalWrite(ry4, 0);
          digitalWrite(ry5, 0); digitalWrite(ry6, 0);
          digitalWrite(ry7, 0); digitalWrite(ry8, 0);
          delay(250);
          // ---------  ALLOFF RELAY 1-8  ----------
          // M5.Lcd.setCursor(40, 120, 4); M5.Lcd.printf("ALL RERAY1 : OFF");
          M5.Lcd.setCursor(0, 10, 4);
          M5.Lcd.println("RERAY1 : OFF");
          M5.Lcd.println("RERAY2 : OFF");
          M5.Lcd.println("RERAY3 : OFF");
          M5.Lcd.println("RERAY4 : OFF");
          M5.Lcd.println("RERAY5 : OFF");
          M5.Lcd.println("RERAY6 : OFF");
          M5.Lcd.println("RERAY7 : OFF");
          M5.Lcd.println("RERAY8 : OFF");

          Serial.flush(); 
          Serial.write("\r\n");        
          break;
     } // Switch
    /* ---------------------------  END  Condition Relay 1-8  -------------------------- */
  } // available
  delay(10);
};
/* -------------------------------------------------------------------------- */
