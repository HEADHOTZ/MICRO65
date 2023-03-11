#define LED1 BCM0
#define LED2 BCM1
#define LED3 BCM2
#define LED4 BCM3
#define LED5 BCM4
#define LED6 BCM5
#define LED7 BCM6
#define LED8 BCM7


void setup() {
  Serial.begin(115200);
  Serial.println();

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('\n');
    Serial.println(str);
    digitalWrite(LED1,str.substring(0,1).toInt());
    digitalWrite(LED2,str.substring(1,2).toInt());
    digitalWrite(LED3,str.substring(2,3).toInt());
    digitalWrite(LED4,str.substring(3,4).toInt());
    digitalWrite(LED5,str.substring(4,5).toInt());
    digitalWrite(LED6,str.substring(5,6).toInt());
    digitalWrite(LED7,str.substring(6,7).toInt());
    digitalWrite(LED8,str.substring(7,8).toInt());
    /*if (str.substring(0, 1) == "1") {
      //digitalWrite(LED1, 1);
    } else Serial.println("LED1 OFF");
    if (str.substring(1, 2) == "1") {
      Serial.println("LED2 ON");
    } else Serial.println("LED2 OFF");*/
  }
}
