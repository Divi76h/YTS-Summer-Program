int LED = 2; 
const int freq = 5000;
const int pwmChannel = 0;
int resolution = 10;

void setup() 
{
 Serial.begin(115200);
 pinMode(LED,OUTPUT);

 ledcSetup(pwmChannel, freq, resolution);
 ledcAttachPin(LED, pwmChannel);
}

void loop() 
{
  if (Serial.available())
  {
    int input = Serial.parseInt();
    ledcWrite(pwmChannel, input);
  }
}
