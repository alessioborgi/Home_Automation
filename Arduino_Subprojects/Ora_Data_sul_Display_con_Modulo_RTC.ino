//Ora e Data Visualizzata su DIsplay tramite Sensore RTC DS3231

//Autore --> Alessio_Borgi
//Classe --> 5AINF
//Copyright © 2020 Alessio Borgi



#include <DS3231.h>                         //Includo la Libreria necessaria per il Sensore RTC DS3231
#include <LiquidCrystal.h>                  //Includo la Libreria necessaria per il Display LCD

DS3231  rtc(SDA, SCL);                      // Assegno alla Variabile di tipo DS3231 i Valori SDA e SCL
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);        //Segue la seguente sintassi  "LiquidCrystal(rs, enable, d4, d5, d6, d7)" corrispondenti al collegamento dei pin su Arduino    

 
void setup() 
{ 
     rtc.begin();                           // Impostazione del Sensore RTC
     lcd.begin(16,2);                       // Impostazione del tipo di Display (Colonne, Righe)
}
void loop() 
{ 
     lcd.setCursor(0,0);                    // Posiziono il Cursore alla colonna 0 e riga 0
     lcd.print("Ora:  ");                   // Scrittura sul Display "ORA"
     lcd.print(rtc.getTimeStr());           // Scrittura sul Display dell'Ora Corrente
     
     lcd.setCursor(0,1);                    // Posiziono il Cursore alla colonna 0 e riga 1
     lcd.print("Data: ");                   // Scrittura sul Display "DATA"
     lcd.print(rtc.getDateStr());           // Scittura sul Display della Data Corrente 
     
     delay(1000);                           //Imposto un ritardo di 1 secondo
}
