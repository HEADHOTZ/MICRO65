#include <M5Stack.h>

int rx_num = 0;

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  Serial.begin(115200);
  // Serial2.begin(unsigned long baud, uint32_t config, int8_t rxPin,
  M5.Lcd.setCursor(100, 0, 4);
  M5.Lcd.print("Serial Revcive Ch");
};

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    int ch = Serial.read();
    Serial.write(ch);
    // ------  Condition ON/OFF Relay  ------- //
    if (ch == 'a') {
      rx_num++;
    }
    // -----------------------------------------
    M5.Lcd.setCursor(30, 120, 4);
    M5.Lcd.printf("rx_num = %d\n", rx_num);
  } // avaolable
  delay(500);
};
