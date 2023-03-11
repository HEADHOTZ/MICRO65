/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLNCWKPa2M"
#define BLYNK_DEVICE_NAME "CONTROL SYSTEM"
#define BLYNK_AUTH_TOKEN "6e4UkdDBQYAR6aoy5bo0Xt6ClV0iBgLH"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <rpcWiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleWioTerminal.h>
#include <rpcWiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleWioTerminal.h>
#include <BH1750.h>
#include <Servo.h>
#include <TFT_eSPI.h>
#include <Wire.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "home229/36";
char pass[] = "1234566495";

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
#define IN1 BCM0
#define IN2 BCM1
#define PWM BCM26
#define RY1 BCM4

BH1750 lightMeter;
TFT_eSPI tft;
Servo myservo;

int servo_val;
int motor_val;
int relay_val;
int vr_val, lux, lux_map, vr_map;
unsigned long previousMillis1 = 0;

BLYNK_WRITE(V3) {
  int degree = param.asInt();
  myservo.write(degree);
  tft.drawString("                                   ", 50, 100);
  tft.drawString(String("Degrees = ") + String(degree), 50, 100);
}

BLYNK_WRITE(V4) {
  int speed = param.asInt();
  motor_val = speed;
  tft.drawString("                                           ", 50, 150);
  tft.drawString(String("Speed = ") + String(motor_val) + " %", 50, 150);
}

BLYNK_WRITE(V5) {
  bool state = param.asInt();
  digitalWrite(RY1, state);
  tft.drawString("                                             ", 50, 200);
  if (digitalRead(RY1) == 1) tft.drawString("Relay = ON", 50, 200);
  else if (digitalRead(RY1) == 0) tft.drawString("Relay = OFF", 50, 200);
}

void setup() {
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  pinMode(WIO_KEY_A, INPUT_PULLUP);
  pinMode(WIO_KEY_B, INPUT_PULLUP);
  pinMode(WIO_KEY_C, INPUT_PULLUP);
  pinMode(BCM27, INPUT);
  pinMode(RY1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM, OUTPUT);

  Serial.begin(115200);
  Wire.begin();
  lightMeter.begin();
  tft.begin();
  Blynk.begin(auth, ssid, pass);

  tft.setRotation(3);
  tft.setTextSize(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  myservo.attach(BCM9);
  myservo.write(90);
  delay(100);
  myservo.write(0);

  tft.drawString("Servo", 0, 0);
  tft.drawString("DC", 125, 0);
  tft.drawString("Relay", 200, 0);
  tft.drawString("Degrees = 0", 50, 100);
  tft.drawString("Speed = 0 %", 50, 150);
  tft.drawString("Relay = OFF", 50, 200);
}

void loop() {
  Blynk.run();
  unsigned long currentMillis = millis();
  vr_val = analogRead(BCM27);
  lux = (int)lightMeter.readLightLevel();
  lux_map = map(lux, 0, 53, 0, 180);
  vr_map = map(vr_val, 2, 1023, 0, 100);

  if (!digitalRead(WIO_KEY_C)) {
    while (!digitalRead(WIO_KEY_C)) delay(10);
    servo_val = lux_map;
    myservo.write(servo_val);
    tft.drawString("                                      ", 50, 100);
    tft.drawString(String("Degrees = ") + String(servo_val), 50, 100);
  }
  if (!digitalRead(WIO_KEY_B)) {
    while (!digitalRead(WIO_KEY_B)) delay(10);
    motor_val = vr_map;
    tft.drawString("                                           ", 50, 150);
    tft.drawString(String("Speed = ") + String(motor_val) + " %", 50, 150);
  }
  if (!digitalRead(WIO_KEY_A)) {
    while (!digitalRead(WIO_KEY_A)) delay(10);
    digitalWrite(RY1, !digitalRead(RY1));
    Blynk.virtualWrite(V5, digitalRead(RY1));
    tft.drawString("                                             ", 50, 200);
    if (digitalRead(RY1) == 1) tft.drawString("Relay = ON", 50, 200);
    else if (digitalRead(RY1) == 0) tft.drawString("Relay = OFF", 50, 200);
  }
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  analogWrite(PWM, motor_val);

  Blynk.virtualWrite(V0, lux_map);
  Blynk.virtualWrite(V1, vr_map);

  tft.drawString(String(lux_map), 0, 50);
  tft.drawString(String(vr_map), 125, 50);
  tft.drawString(String(digitalRead(RY1)), 225, 50);

  if ((currentMillis - previousMillis1) >= 200) {
    tft.drawString("                         ", 0, 50);
    tft.drawString("                         ", 125, 50);
    tft.drawString("                         ", 225, 50);
    previousMillis1 = millis();
  }
}