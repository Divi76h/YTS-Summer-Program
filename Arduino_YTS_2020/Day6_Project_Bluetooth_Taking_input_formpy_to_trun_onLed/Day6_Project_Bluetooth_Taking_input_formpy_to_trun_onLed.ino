#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

const int LED = 2;

void setup() 
{
  SerialBT.begin("Divi76hs_ESP32");
  pinMode(LED, OUTPUT);
}

void loop()
{
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
