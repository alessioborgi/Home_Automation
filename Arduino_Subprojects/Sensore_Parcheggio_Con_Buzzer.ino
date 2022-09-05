//Sensore Parcheggio Con Buzzer

//Autore --> Alessio_Borgi
//Classe --> 5AINF
//Copyright © 2020 Alessio Borgi





int Trigger_Port = 7;                                // Dichiarazione Porta Trigger
int Echo_Port = 8;                                   // Dichiarazione Porta Echo
int Buzzer = 9;                                      // Dichiarazione Buzzer
unsigned long time;                                  // Dichiarazione Tempo
unsigned long Tempo_Lampeggio;                       // Dichiarazione Tempo Lampeggio
unsigned long Tempo_Pausa;                           // Dichiarazione Tempo Pausa


void setup()
{
  pinMode( Trigger_Port, OUTPUT );                   // Pongo la Porta Trigger in Output
  pinMode( Echo_Port, INPUT );                       // Pongo la Porta Echo in Input
  pinMode( Buzzer, OUTPUT );                         // Pongo il Buzzer in Output
  Serial.begin( 9600 );                              // Inizializzazione Comunicazione Seriale
  Serial.println( "Sensore ultrasuoni: ");           // Scrittura al Monitor Seriale
}

void loop()
{
  
  digitalWrite( Trigger_Port, LOW );                 // Uscita della porta Trigger impostata a Bassa
  digitalWrite( Trigger_Port, HIGH );                // Invia un impulso di 10microsec su trigger
  delayMicroseconds( 10 );                           // Ritardo di 10 millisecondi
  digitalWrite( Trigger_Port, LOW );                 // Uscita della porta Trigger impostata a Bassa 
  long duration = pulseIn( Echo_Port, HIGH );        // Impostazione della variabile Duration 
  long r = 0.034 * duration / 2;                     // Impostazione del Calcolo del Rumore
  Serial.print( "durata: " );                        // Scrittura al Monitor Seriale della "Durata"
  Serial.print( duration );                          // Scrittura al Monitor Seriale della Durata Misurata
  Serial.print( " , " );
  Serial.print( "distanza: " );                      // Scrittura al Monitor Seriale della "Distanza"
  if ( duration > 38000 )                            // Controllo sulla Distanza da Misurare
  {
    Serial.println( "fuori portata");                // Se la Distanza è troppo scrivo al Monitor Seriale che è fuori Portata 
  }
  else 
  {
    Serial.print( r );                               // Altrimenti Scrivo al Monitor Seriale la distanza in Centimetri
    Serial.println( "cm" );
  }
  if ( r > 3 && r <= 200)                            // Controllo Imposto un rumore Proporzionato alla Vicinanza
  {
    delay(r * 10);
    digitalWrite(Buzzer, HIGH);
    delay(r * 10);
  }
  if ( r <= 3)                                       // Controllo sul Rumore
  {
    digitalWrite(Buzzer, HIGH);
    delay(1000);
  }
  digitalWrite(Buzzer, LOW);                         // Spengo il Buzzer se non vi si rileva una Distanza da misurare
}
