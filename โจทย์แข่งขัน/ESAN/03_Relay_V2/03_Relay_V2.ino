/* *********************************************************************
    1.Press Switch To Togle Relay                                      *  
    2.Show Status Relay ON/OFF                                         *                                         
 * *********************************************************************/
#include"TFT_eSPI.h"
#include"Free_Fonts.h" //include the header file
TFT_eSPI tft;

#define Sw1 D0
#define Sw2 D1
#define Sw3 D2
#define Sw4 D3
#define Ry1 D4
#define Ry2 D5
#define Ry3 D6
#define Ry4 D7
boolean stRy1 = 0;
boolean stRy2 = 0;
boolean stRy3 = 0;
boolean stRy4 = 0;

/* ******************************************************************** */
void setup() {
  pinMode(Sw1, INPUT);
  pinMode(Sw2, INPUT);
  pinMode(Sw3, INPUT);
  pinMode(Sw4, INPUT);
  pinMode(Ry1, OUTPUT);
  pinMode(Ry2, OUTPUT);
  pinMode(Ry3, OUTPUT);
  pinMode(Ry4, OUTPUT);

  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLUE); //Black background

  digitalWrite(Ry1, 0);
  digitalWrite(Ry2, 0);
  digitalWrite(Ry3, 0);
  digitalWrite(Ry4, 0);
};

void loop() {
  // -------  Disolay Status Relay On TFT LCD  ------ //
  tft.setFreeFont(FF44);                     //select Free, Sans, Bold, Oblique, 12pt
  tft.setTextColor(TFT_WHITE, TFT_BLUE);     // Clear Display Anty Font Replace :  Fill Coler ,Font Color
  
  // -------------  ON/OFF Relay:1-4  -------------- //
  if (digitalRead(Sw1) == 0) { // ON/OFF Relay:1
    while (digitalRead(Sw1) == 0) delay(10);
    digitalWrite(Ry1, !(digitalRead(Ry1)));
    // ----- Show Display ON/OFF  -----
    stRy1 = !stRy1;                         // Togle Status Relay
    if (stRy1 == 1)
      tft.drawString("R1:ON   ", 90, 100);
    else
      tft.drawString("R1:OFF", 90, 100);
  }
  if (digitalRead(Sw2) == 0) {  // ON/OFF Relay:2
    while (digitalRead(Sw2) == 0) delay(10);
    digitalWrite(Ry2, !(digitalRead(Ry2)));

    stRy2 = !stRy2;
    if (stRy2 == 1)
      tft.drawString("R2:ON   ", 90, 100);
    else
      tft.drawString("R2:OFF", 90, 100);

  }
  if (digitalRead(Sw3) == 0) {  // ON/OFF Relay:3
    while (digitalRead(Sw3) == 0) delay(10);
    digitalWrite(Ry3, !(digitalRead(Ry3)));

    stRy3 = !stRy3;
    if (stRy3 == 1)
      tft.drawString("R3:ON   ", 90, 100);
    else
      tft.drawString("R3:OFF", 90, 100);
  }
  if (digitalRead(Sw4) == 0) { // ON/OFF Relay:4
    while (digitalRead(Sw4) == 0) delay(10);
    digitalWrite(Ry4, !(digitalRead(Ry4)));

    stRy4 = !stRy4;
    if (stRy4 == 1)
      tft.drawString("R4:ON   ", 90, 100);
    else
      tft.drawString("R4:OFF", 90, 100);
  }
  // ------------------------------------------------  //
};
