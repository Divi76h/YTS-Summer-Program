#include <SPI.h>
#include <MFRC522.h>
 
const int resetPin = 22; 
const int ssPin = 21;    
 
MFRC522 mfrc522 = MFRC522(ssPin, resetPin); 
 
void setup() 
{
  Serial.begin(115200);
  SPI.begin();   
  
  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial();  
}
 
void loop() {}
