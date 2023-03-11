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

 M5.Lcd.setCursor(80, 0, 4);  M5.Lcd.print("Serial Revcive Ch");
};
/* -------------------------------------------------------------------------- */
void loop() {
  if (Serial.available()) {
    int ch = Serial.read();
    Serial.write(ch);
    /* ---------------------------   Condition Relay ON/OFF   -------------------------- */
    // ------ ON/OFF Relay1  ------- //
    if (ch == 'a' or ch == 'A') {
      stRy1 = !stRy1;
      digitalWrite(ry1, stRy1); delay(100);
      if (stRy1 == 1) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.print("RERAY1 : ON   ");
      }
      if (stRy1 == 0) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.print("RERAY1 : OFF");
      }
    } // 'a'
    // ------  ON/OFF Relay2  ------- //
    if (ch == 'b' || ch == 'B') {
      stRy2 = !stRy2;
      digitalWrite(ry2, stRy2); delay(100);
      if (stRy2 == 1) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.print("RERAY2 : ON   ");
      }
      if (stRy2 == 0) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.print("RERAY2 : OFF");
      }
    }    // 'b'
    // ------  ON/OFF Relay3  ------- //
    if (ch == 'c' or ch == 'C' ) {
      stRy3 = !stRy3;
      digitalWrite(ry3, stRy3); delay(100);
      if (stRy3 == 1) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.print("RERAY3 : ON     ");
      }
      if (stRy3 == 0) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.print("RERAY3 : OFF    ");
      }
    }  // 'c'
    // ------  ON/OFF Relay4  ------- //
    if (ch == 'd' or ch == 'D') {
      stRy4 = !stRy4;
      digitalWrite(ry4, stRy4); delay(100);
      if (stRy4 == 1) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.print("RERAY4 : ON      ");
      }
      if (stRy4 == 0) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.print("RERAY4 : OFF    ");
      }
    } // 'd'
    // ------  ON/OFF Relay5  ------- //
    if (ch == 'e' or ch == 'E') {
      stRy5 = !stRy5;
      digitalWrite(ry5, stRy5); delay(100);
      if (stRy5 == 1) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.print("RERAY5 : ON      ");
      }
      if (stRy5 == 0) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.print("RERAY5 : OFF    ");
      }
    }   // 'e'
    // ------  ON/OFF Relay6  ------- //
    if (ch == 'f' or ch == 'F') {
      stRy6 = !stRy6;
      digitalWrite(ry6, stRy6); delay(100);
      if (stRy6 == 1) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.printf("RERAY6 : ON     ");
      }
      if (stRy6 == 0) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.printf("RERAY6 : OFF    ");
      }
    }   // 'f'
    // ------  ON/OFF Relay7  ------- //
    if (ch == 'i' or ch == 'I') {
      stRy7 = !stRy7;
      digitalWrite(ry7, stRy7); delay(100);
      if (stRy7 == 1) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.printf("RERAY7 : ON     ");
      }
      if (stRy7 == 0) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.printf("RERAY7 : OFF  ");
      }
    }   // 'i'
    // ------  ON/OFF Relay8  ------- //
    if (ch == 'j' or ch == 'J') {
      stRy8 = !stRy8;
      digitalWrite(ry8, stRy8); delay(100);
      if (stRy8 == 1) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.printf("RERAY8 : ON     ");
      }
      if (stRy8 == 0) {
        M5.Lcd.setCursor(40, 100, 4); M5.Lcd.printf("RERAY8 : OFF   ");
      }
    } // 'j'
    // ------  Condition OFF Al Relay 1-8   ------- //
    if (ch == 'k' or ch == 'K') {
      digitalWrite(ry1, 0); digitalWrite(ry2, 0);
      digitalWrite(ry3, 0); digitalWrite(ry4, 0);
      digitalWrite(ry5, 0); digitalWrite(ry6, 0); 
      digitalWrite(ry7, 0); digitalWrite(ry8, 0); 
      delay(250);
      // ---------  ALLOFF RELAY 1-8  ----------
      // M5.Lcd.setCursor(40, 120, 4); M5.Lcd.printf("ALL RERAY1 : OFF");
      M5.Lcd.setCursor(40, 100, 4);
      M5.Lcd.println("ALL RERAY OFF");

      stRy1 = 0;  stRy2 = 0;  stRy3 = 0;  stRy4 = 0;
      stRy5 = 0;  stRy6 = 0;  stRy7 = 0;  stRy8 = 0;
      //Serial.flush();
    }  // 'k'
    /* ---------------------------  END  Condition Relay 1-8  -------------------------- */
  } // available
  delay(100);
};
/* -------------------------------------------------------------------------- */
