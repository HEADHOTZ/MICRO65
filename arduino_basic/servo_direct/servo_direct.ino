#include <Servo.h>
Servo myservo;

void setup() {
  myservo.attach(BCM9);
}

void loop() {
  myservo.write(20);
  delay(2000);
  myservo.write(90);
  delay(2000);
  myservo.write(170);
  delay(2000);
}