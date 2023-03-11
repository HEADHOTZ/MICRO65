#define LED1 BCM0
#define LED2 BCM1
#define LED3 BCM2
#define LED4 BCM3
#define LED5 BCM4
#define LED6 BCM5
#define LED7 BCM6
#define LED8 BCM7

void setup() {
  Serial.begin(115200);  // initialize serial communication
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
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');  // read the incoming ASCII code
    for (int i = 0; i < input.length(); i++) {
      char c = input[i];
      Serial.print("ASCII value of ");
      Serial.print(c);
      Serial.print(" is ");
      Serial.println(decToBinary(c));  // convert and print the binary value
      Serial.println(decToBinary(c).substring(0, 1));
      digitalWrite(LED1, decToBinary(c).substring(0, 1).toInt());
      digitalWrite(LED2, decToBinary(c).substring(1, 2).toInt());
      digitalWrite(LED3, decToBinary(c).substring(2, 3).toInt());
      digitalWrite(LED4, decToBinary(c).substring(3, 4).toInt());
      digitalWrite(LED5, decToBinary(c).substring(4, 5).toInt());
      digitalWrite(LED6, decToBinary(c).substring(5, 6).toInt());
      digitalWrite(LED7, decToBinary(c).substring(6, 7).toInt());
      digitalWrite(LED8, decToBinary(c).substring(7, 8).toInt());
    }
  }
}

String decToBinary(char c) {
  String binary = "";
  for (int i = 7; i >= 0; i--) {
    binary += (c >> i) & 1;
  }
  return binary;
}
