#include <Servo.h>

static const int servoPin = 33;
Servo servo1;                                                                                                                

void setup() 
{
  Serial.begin(115200);
  servo1.attach(servoPin);
}

void loop() {
  servo1.write(180);
  Serial.print("MOVING");
  delay(2000);
  servo1.write(0);
  Serial.print("MOVING");
  delay(2000);
}
