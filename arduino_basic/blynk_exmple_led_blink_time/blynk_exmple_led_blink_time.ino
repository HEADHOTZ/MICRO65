#define BLYNK_PRINT Serial
#define LED D1
#define SW1 D3
#define SW2 D4
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "850bbb64791348858c06c620e94be7e0";
char ssid[] = "wifi name";
char pass[] = "wifi password";
BlynkTimer timer;
WidgetLED led(V1);
void timerEvent()
{
  if(digitalRead(LED)==HIGH)
    led.on();
  else
    led.off();
}
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2000L, timerEvent);
  pinMode(LED,OUTPUT);
  pinMode(SW1,INPUT_PULLUP);
  pinMode(SW2,INPUT_PULLUP);   
}
void loop()
{
  Blynk.run();
  timer.run(); // run BlynkTimer
  if(digitalRead(SW1)==LOW)
    digitalWrite(LED,HIGH);
  else if (digitalRead(SW2)==LOW)
    digitalWrite(LED,LOW);
}