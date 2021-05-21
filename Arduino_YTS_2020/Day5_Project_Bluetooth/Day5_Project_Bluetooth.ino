#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() 
{
  SerialBT.begin("Divi76hs_ESP32");
}

void loop() 
{
  SerialBT.println("Hello World!!");
  delay(500);
}                                  
