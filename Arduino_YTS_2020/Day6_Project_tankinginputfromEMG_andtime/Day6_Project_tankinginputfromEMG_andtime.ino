int sensorValue = 0;
long t = 0, ti = 0;

void setup()
{
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
  delay(50);
}
