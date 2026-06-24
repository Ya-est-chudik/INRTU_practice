void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
}

uint32_t flag_op_cl = 0;
uint32_t flag_notif = 0;
void loop() {
  if (flag_op_cl == 0) {
    digitalWrite(5, LOW);
    digitalWrite(9, HIGH);
    if (analogRead(A0) > 512) {
      Serial.println("Open");
      flag_op_cl = 1;
    } else {
      flag_op_cl = 0;
    }
  } else {
    digitalWrite(9, LOW);
    digitalWrite(5, HIGH);
    delay(5000);
    if (analogRead(A0) > 512) {
      flag_op_cl = 1;
    } else {
      Serial.println("Close");
      flag_op_cl = 0;
    }
  }
}