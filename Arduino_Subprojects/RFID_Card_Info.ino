//New Card ID Info
//Mr_Technology_Arduino Project
// Copyright © 2020 Alessio Borgi
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          
#define SS_PIN          10        

MFRC522 mfrc522(SS_PIN, RST_PIN);  

void setup() 
{
  	Serial.begin(9600);		
  	while (!Serial);		
  	SPI.begin();			
  	mfrc522.PCD_Init();		
  	delay(4);				
  	mfrc522.PCD_DumpVersionToSerial();	
  	Serial.println(F("Avvicina il Badge per Ottenere informazioni sul suo ID..."));
}

void loop() 
{
	  if ( ! mfrc522.PICC_IsNewCardPresent()) 
	  {
		  return;
	  }

	  if ( ! mfrc522.PICC_ReadCardSerial()) 
	  {
		  return;
	  }
	mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
