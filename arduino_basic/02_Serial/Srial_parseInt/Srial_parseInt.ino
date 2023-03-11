const int ry1 = 17;
void setup()
{
  pinMode(ry1, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  while (Serial.available() > 0) // ถ้ามีการสื่อสารทาง Serial เข้ามา
  {
    if (Serial.read() == '\n') { // ถ้าค่าที่อ่านได้เป็น '\n' แสดงว่าจบค่าที่ส่งแล้ว
      int val = Serial.parseInt(); // อ่านค่าที่ส่งเข้ามาแล้วแปลงเป็นตัวเลข
      Serial.println(val); // แสดงค่าที่อ่านได้ ออกไปที่จอ Serial Monitor

      if (val == 1) { // ประมวลผลจากข้อมูลที่ส่งเข้ามาทาง Serial เพื่อควบคุมตามที่ต้องการ
        digitalWrite(ry1, 0);
      } else if (val == 0) {
        digitalWrite(ry1, 1);
      }
    }
  }
  delay(500);
}
