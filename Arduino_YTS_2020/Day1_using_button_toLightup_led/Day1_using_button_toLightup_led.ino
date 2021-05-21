const int buttonPin = 17;
const int ledPin = 14;
int buttonState = 0;
void setup() {
  Serial.begin(9600);
  pinMode(14, OUTPUT);
  pinMode(17, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH)
  {
    digitalWrite(ledPin, HIGH); 
    delay(100);
  }
  else
  {
    digitalWrite(ledPin, LOW);
    delay(100);
  }  
  
}
