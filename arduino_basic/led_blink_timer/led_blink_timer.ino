#define ledPin1 0
#define ledPin2 1
#define swPin 2
int timer = 0;
int sw_state = 0;
int led1_state = 0;
int led2_state = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}
void loop() {
  if (!digitalRead(swPin)) {
    while (!digitalRead(swPin)) delay(10);
    sw_state++;
    timer = 0;
  }
  if (timer == 20) {
    if (sw_state == 1) {
      if (led1_state == 0) {
        digitalWrite(ledPin1, HIGH);
        sw_state = 0;
        led1_state = 1;
      }  // if led1 == 0
      else if (led1_state == 1) {
        digitalWrite(ledPin1, LOW);
        sw_state = 0;
        led1_state = 0;
      }  //  if led1 == 1
    }    //  if sw == 1
    else if (sw_state == 2) {
      if (led2_state == 0) {
        digitalWrite(ledPin2, HIGH);
        sw_state = 0;
        led2_state = 1;
      }  //  if led2 == 0
      else if (led2_state == 1) {
        digitalWrite(ledPin2, LOW);
        sw_state = 0;
        led2_state = 0;
      }  //  if led2 == 1
    }    //  if sw == 2
  }      //  if timer == 20
  timer++;
  Serial.println(sw_state);
  Serial.println(timer);
  delay(100);
};