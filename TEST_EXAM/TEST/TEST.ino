#define sw1 0
#define sw2 1
#define sw3 2
#define sw_clear 3
#define led1 4
#define led2 5
#define led3 6
bool state1 = 0;
bool state2 = 0;
bool state3 = 0;
void setup() {
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw_clear, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  if (!digitalRead(sw1))
  {
    while (!digitalRead(sw1))
    {
      delay(10);
    }
    if (state1 == 0)
    {
      state1 = 1;
      digitalWrite(led1, HIGH);
      Serial.println("LED1 : ON");
    }
    else if (state1 == 1)
    {
      state1 = 0;
      digitalWrite(led1, LOW);
      Serial.println("LED1 : OFF");
    }
  }
  else if (!digitalRead(sw2))
  {
    while (!digitalRead(sw2))
    {
      delay(10);
    }
    if (state2 == 0)
    {
      state2 = 1;
      digitalWrite(led2, HIGH);
      Serial.println("LED2 : ON");
    }
    else if (state2 == 1)
    {
      state2 = 0;
      digitalWrite(led2, LOW);
      Serial.println("led2 : OFF");
    }
  }

  else if (!digitalRead(sw3))
  {
    while (!digitalRead(sw3))
    {
      delay(10);
    }
    if (state3 == 0)
    {
      state3 = 1;
      digitalWrite(led3, HIGH);
      Serial.println("led3 : ON");
    }
    else if (state3 == 1)
    {
      state3 = 0;
      digitalWrite(led3, LOW);
      Serial.println("led3 : OFF");
    }
  }
  else if (!digitalRead(sw_clear))
  {
    while (!digitalRead(sw_clear))
    {
      delay(10);
    }
    state1 = 0;
    state2 = 0;
    state3 = 0;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    Serial.println("LED : CLEAR");
  }
}
