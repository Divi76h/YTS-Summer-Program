#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() 
{
  Serial.begin(115200);
  SerialBT.begin("Divi76hs_ESP32");
}

int a = 0;

void loop()
{
  if(SerialBT.available())
  {
    a = SerialBT.parseInt();
    Serial.println(a);             
  }
}
