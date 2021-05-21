int sensorValue = 0;

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  sensorValue = analogRead(35);
  Serial.print(sensorValue);
  Serial.println();
  delay(20);
}
