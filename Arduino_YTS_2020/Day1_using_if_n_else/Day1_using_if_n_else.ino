void setup()
{
  Serial.begin(9600);

}

void loop() 
{
  if(Serial.available())
  {
    int input = Serial.parseInt();
    
    if(input == 1)
    {
      Serial.print("Hello!");
      Serial.print("\n");
    }
    else if(input == 2)
    {
      Serial.print("Bye!");
      Serial.print("\n");
    }
    else if(input != 1 & input != 2)
    {
      Serial.print("Invalid Input");
      Serial.print("\n");
    }
    
  }

}
