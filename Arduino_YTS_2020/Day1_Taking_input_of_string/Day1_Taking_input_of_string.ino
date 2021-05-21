void setup() {
  Serial.begin(9600);

}

void loop() {
  if(Serial.available())
  {
    String input = Serial.readString();

    Serial.print(input);
    Serial.print("\n");
  }


}
