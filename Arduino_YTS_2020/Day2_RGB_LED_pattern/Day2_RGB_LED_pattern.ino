const int ledPin2 = 12;
const int ledPinin = 14;
const int ledPin1 = 27;
const int ledPin3 = 26;
const int Delay = 500;

void setup() 
{
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  digitalWrite(ledPinin, HIGH);
}

void loop() 
{
  digitalWrite(ledPin1, HIGH);
  delay(Delay);
  digitalWrite(ledPin2, HIGH);
  delay(Delay);
  digitalWrite(ledPin1, LOW);
  delay(Delay);
  digitalWrite(ledPin3, HIGH);
  delay(Delay);
  digitalWrite(ledPin2, LOW);
  delay(Delay);
  digitalWrite(ledPin1, HIGH);
  delay(Delay);
  digitalWrite(ledPin2, HIGH);
  delay(Delay);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin1, LOW);
}
