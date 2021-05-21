const int ledPin1 = 12;
const int ledPin2 = 14;
const int ledPin3 = 27;
const int ledPin4 = 26;

void setup() 
{
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
}

void loop() 
{
  digitalWrite(ledPin1, HIGH);
  delay(100);
  digitalWrite(ledPin2, HIGH);
  delay(100);
  digitalWrite(ledPin3, HIGH);
  delay(100);
  digitalWrite(ledPin4, HIGH);
  delay(100);
  digitalWrite(ledPin1, LOW);
  delay(100);
  digitalWrite(ledPin2, LOW);
  delay(100);
  digitalWrite(ledPin3, LOW);
  delay(100);
  digitalWrite(ledPin4, LOW);
  delay(100);
}
