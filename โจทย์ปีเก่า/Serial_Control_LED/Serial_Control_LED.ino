#define LED1 BCM0
#define LED2 BCM1
#define LED3 BCM2

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    String key = Serial.readStringUntil('\n');
    Serial.println(key);
    if (key == "ON 1") {
      digitalWrite(LED1, 1);
      Serial.println("LED1 ON");
    }
    if (key == "ON 2") {
      digitalWrite(LED2, 1);
      Serial.println("LED2 ON");
    }
    if (key == "ON 3") {
      digitalWrite(LED3, 1);
      Serial.println("LED3 ON");
    }
    if (key == "OFF 1") {
      digitalWrite(LED1, 0);
      Serial.println("LED1 OFF");
    }
    if (key == "OFF 2") {
      digitalWrite(LED2, 0);
      Serial.println("LED2 OFF");
    }
    if (key == "OFF 3") {
      digitalWrite(LED3, 0);
      Serial.println("LED3 OFF");
    }
    if (key == "ALL ON") {
      digitalWrite(LED1, 1);
      digitalWrite(LED2, 1);
      digitalWrite(LED3, 1);
      Serial.println("ALL ON");
    }
    if (key == "ALL OFF") {
      digitalWrite(LED1, 0);
      digitalWrite(LED2, 0);
      digitalWrite(LED3, 0);
      Serial.println("ALL OFF");
    }
  }
}
