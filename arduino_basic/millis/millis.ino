#define led1 BCM0
#define led2 BCM1
bool ledState1 = false;
bool ledState2 = false;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, ledState1);
  digitalWrite(led2, ledState2);
}

void loop() {
  unsigned long currentMillis = millis();
  if ((currentMillis - previousMillis1) >= 100) {
    ledState1 = !ledState1;         // "toggles" the state
    digitalWrite(led1, ledState1);  // sets the LED based on ledState

    previousMillis1 = millis();  // save the "current" time
  }
  if ((currentMillis - previousMillis2) >= 1000) {
    ledState2 = !ledState2;         // "toggles" the state
    digitalWrite(led2, ledState2);  // sets the LED based on ledState

    previousMillis2 = millis();  // save the "current" time
  }
};