const int LED = 2;

void setup() 
{
  Serial.begin(115200);
  pinMode(LED,OUTPUT);
}

void loop() 
{
  if(Serial.available())
  {
    int cmd = Serial.parseInt();
    if(cmd == 1)
    {
      digitalWrite(LED, HIGH);
    }
    else
    {
      digitalWrite(LED, LOW);
    }
  }
}
