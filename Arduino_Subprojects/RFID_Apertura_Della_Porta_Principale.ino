//Apertura Della Porta Principale con Sensore RFID

//Autore --> Alessio_Borgi
//Classe --> 5AINF
//Copyright © 2020 Alessio Borgi


#include <SPI.h>                    // SPI è un protocollo dati seriale sincrono utilizzato dai microcontrollori per comunicare rapidamente con uno o più dispositivi periferici su brevi distanze
#include <MFRC522.h>                // Libreria utilizzata per il Sensore RFID
#include <Servo.h>                  // LIbreria utilizzata per il Servomotore
 
#define SS_PIN 10                   // Definizione del Pin 10 riguardante il Sensore RFID
#define RST_PIN 9                   // Definizione del Pin 9 riguardante il Sensore RFID
#define LED_V 5                     // Definizione del Pin del Led Verde
#define LED_R 4                     // Definizione del Pin del Led Rosso
#define BUZZER 2                    // Definizione del Pin del Buzzer
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Creazione di una Istanza MFRC522 
Servo myServo;                      // Definizione del ServoMotore
 
void setup() 
{
  Serial.begin(9600);                // Inizializzazione Comunicazione Seriale
  SPI.begin();                       // Inizializzazione dello SPI Bus
  mfrc522.PCD_Init();                // Inizializzazione MFRC522
  myServo.attach(3);                 // Inizializzazione del ServoMotore
  myServo.write(180);                  // Posizione d'Inizio del ServoMotore
  pinMode(LED_V, OUTPUT);            // Pongo il Led Verde in Output
  pinMode(LED_R, OUTPUT);            // Pongo il Led Rosso in Output
  pinMode(BUZZER, OUTPUT);           // Pongo il Buzzer in Output
  noTone(BUZZER);                    // Interrompe Inizialmente il rumore del Buzzer
  Serial.println("Put your card to the reader...");  
  Serial.println();

}
void loop() 
{
  
  if ( ! mfrc522.PICC_IsNewCardPresent())       // Ricerco nuove carte
  {
    return;
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial())         // Seleziono una delle Carte
  {
    return;
  }
  
  Serial.print("UID tag :");                    // Mostro l'UID nel Monitor Seriale
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "D2 21 D4 1B"  || content.substring(1) == "67 80 8E 26") // Controllo se gli UID riconosciuti corrispondono a quelli che ho Registrato come Idonei
  {
    Serial.println("Authorized access");      // Se corrisponde ad un UID Idoneo  mostro l'accesso autorizzato
    Serial.println();
    delay(500);
    digitalWrite(LED_V, HIGH);                // Accendo il Led Verde
    tone(BUZZER, 500);
    delay(300);
    noTone(BUZZER);                           // Attivo il Rumore del Buzzer
    myServo.write(90);                       // Faccio compiere un movimento di 180 Gradi al ServoMotore
    delay(5000);
    myServo.write(180);                         // Stoppo il Servomotore dopo il movimento effettuato
    digitalWrite(LED_V, LOW);                 // Spengo il led Verde
  }
 
  else   
  {
    Serial.println(" Access denied");         // Se non corrisponde ad un UID Idoneo  mostro l'accesso negato  
    digitalWrite(LED_R, HIGH);                // Accendo il Led Rosso
    tone(BUZZER, 300);                        // Attivo un Rumore più cupo del Buzzer
    delay(1000);
    digitalWrite(LED_R, LOW);                 // Spengo il Led Rosso
    noTone(BUZZER);                           // Spengo il Buzzer
  }
}
