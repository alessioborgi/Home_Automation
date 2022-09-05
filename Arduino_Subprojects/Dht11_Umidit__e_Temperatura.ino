//Sensore DHT-11 che consente di leggere sul display la temperatura e l'umidità 

//Autore --> Alessio_Borgi
//Classe --> 5AINF
//Copyright © 2020 Alessio Borgi





#include <DHT.h>
#include <LiquidCrystal.h>
#include "DHT.h"


#define DHTPIN 8                                          // 8 è il pin di Arduino a cui collego il sensore di temperatura
#define DHTTYPE DHT11                                     // dht11 è il tipo di sensore che uso


DHT dht(DHTPIN, DHTTYPE);                                 // Assegno alla Variabile di tipo DHT il suo Pin e il suo Tipo
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);                    // Connessione con il Display(pin che sono connessi al display)

 
void setup() 
{
    lcd.begin(16, 2);                   // Impostazione del tipo di Display (Colonne, Righe)
    lcd.print("Temperatura");           // Scrittura sul Display "Temperatura"
    lcd.setCursor(15,0);                // Posiziono il Cursore alla colonna 15 e riga 0
    lcd.print("C");                     // Scrittura sul Display dell'unità "Celsius"
    lcd.setCursor(0,1);                 // Posiziono il Cursore alla colonna 0 e riga 1 in modo da scrivere "Temperatura"
    lcd.print("Umidita'");              // Scrittura sul Display "Umidità"
    lcd.setCursor(15,1);                // Posiziono il Cursore alla colonna 15 e riga 1
    lcd.print("%");                     // Scrittura sul Display dell'unità "Percentuale"
}



void loop() 
{
    int t = dht.readTemperature();      // Metto nella variabile "t" la lettura della Temperatura        
    int h = dht.readHumidity();         // Metto nella variabile "h" la lettura dell'Umidità             
    lcd.setCursor(12, 0);               // Posiziono il Cursore alla colonna 14 e riga 0 
    lcd.print(t);                       // Scrittura sul Display della Temperatura(t)                 
    lcd.setCursor(12, 1);               // Posiziono il Cursore alla colonna 14 e riga 1 
    lcd.print(h);                       // Scrittura sul Display dell'Umidità(h)
}
