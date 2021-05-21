#include <Servo.h>

static const int servoPin = 33;
Servo servo1;  

int sensorValue = 0;
long t = 0, ti = 0;

void setup()
{
  pinMode(4, OUTPUT);
  servo1.attach(servoPin);
  Serial.begin(115200);
  ti = millis();
}

void loop()
{
  t = millis() - ti;
  sensorValue = analogRead(35);

  Serial.print(t);
  Serial.print(",");
  Serial.print(sensorValue);
  Serial.println();
  delay(10);

  if (Serial.available())
  {
    int input = Serial.parseInt();
    if (input == 1)
    {
      servo1.write(180);
      digitalWrite(4, HIGH);
    }
    else if (input == 0)
    {
      digitalWrite(4, LOW);
      servo1.write(0);
    }
  }
}
