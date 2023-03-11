String str = "";

void setup() {
  Serial.begin(115200);         // opens serial port, sets data rate to 9600 bps
}
void loop() {
  if (Serial.available() > 0) {
    str = Serial.readString();// read the incoming data as string
    Serial.print("I received : ");
    Serial.println(str);

    if (str == "ry1") {
      Serial.println("OK");
    }
  }
  delay(10);
};
