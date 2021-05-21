void setup() {
  Serial.begin(9600);

}

void loop() {
  if(Serial.available())
  {
    int input = Serial.parseInt();

    Serial.print(input);
    Serial.print("\n");
  }

}
