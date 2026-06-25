#include <Servo.h>
Servo myservo;

uint16_t old_angle = 0;

void setup() {
  Serial.begin(115200);
  myservo.attach(3);
  myservo.write(0);
  Serial.println("Enter:");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    uint16_t angle = input.toInt();
    
    if (angle >= old_angle) {
      for (uint16_t i = old_angle; i <= angle; ++i) {
        myservo.write(i);
        delay(15);
      }
    } else {
      for (uint16_t i = old_angle; i >= angle; --i) {
        myservo.write(i);
        delay(15);
      }
    }
    old_angle = angle;
  }
}