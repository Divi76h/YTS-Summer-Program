#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

const int LED = 2;
int sensorValue = 0;
long t = 0, ti = 0;

void setup() 
{
  Serial.begin(115200);
  ti = millis();
  pinMode(LED,OUTPUT);
  SerialBT.begin("Divi76hs_ESP32");
}

void loop() 
{
  sensorValue = analogRead(35);
  t = millis() - ti;
  Serial.print(t);
  Serial.print(",");
  Serial.print(sensorValue);
  Serial.println();
  delay(20);
  
  if(SerialBT.available())
  {
    int cmd = SerialBT.parseInt();
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
