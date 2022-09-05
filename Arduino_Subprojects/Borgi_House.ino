//Borgi House
//Accensione Led, Rotazione Servomotore per apertura Porta. Tutto questo da APP anche tramite comando Vocale.

//Autore --> Alessio_Borgi
//Classe --> 5AINF

#include <SoftwareSerial.h>
#include <Servo.h>
#include <Stepper.h>

SoftwareSerial SSerial(6, 7); //6 RX e 7 TX
int stepsPerRevolution = 500; //Velocità Ventilatore
Stepper myStepper(stepsPerRevolution, 10, 11, 12, 13); // Dichiarazione Pin Motori DC

Servo servo1;                 //Dichiarazione di un Oggetto di tipo Servo


void setup() 
{
  Serial.begin(9600);
  while(!Serial) {}

  Serial.println("ok");
  SSerial.begin(9600);

  pinMode(A0, OUTPUT);      //Dichiarazione dei Pin su cui Giacciono i Led e il Servomotore
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  servo1.attach(3);
  
}

String line = "";


void loop() 
{  
  if (SSerial.available())
  {
     char ch = SSerial.read();        
    if ((ch == '\n') || (ch == '\r'))
    {
      process(line);
      line = ""; // Clear recieved buffer      
    } 
    else 
    {
      line += ch;  
    }
  }
}




//Funzione che gestisce ciò che arriva dall'APP

void process(String line) 
{
  Serial.print("Arduino Received: ");
  Serial.println("#"+line+"#");
  Serial.println(line.length());

  //Inizio Parte Testuale dall'APP
  
  //Soggiorno
  if (line.equals("a")) 
  {
      digitalWrite(A0, HIGH);
      Serial.println("Soggiorno ON");
  }
  if (line.equals("b")) 
  {
      digitalWrite(A0, LOW);
      Serial.println("Soggiorno OFF");
  }

  //Camera
  if (line.equals("c")) 
  {
      digitalWrite(A1, HIGH);
      Serial.println("Camera ON");
  }
  if (line.equals("d")) 
  {
      digitalWrite(A1, LOW);
      Serial.println("Camera OFF");
  }

  //Cucina
  if (line.equals("e")) 
  {
      digitalWrite(A2, HIGH);
      Serial.println("Cucina ON");
  }
  if (line.equals("f")) 
  {
      digitalWrite(A2, LOW);
      Serial.println("Cucina OFF");
  }

  //Bagno
  if (line.equals("g")) 
  {
      digitalWrite(A3, HIGH);
      Serial.println("Bagno ON");
  }
  if (line.equals("h")) 
  {
      digitalWrite(A3, LOW);
      Serial.println("Bagno OFF");
  }

  //Forno
  if (line.equals("i")) 
  {
      digitalWrite(9, HIGH);
      Serial.println("Forno ON");
  }
  if (line.equals("j")) 
  {
      digitalWrite(9, LOW);
      Serial.println("Forno OFF");
  }

  //Letto
  if (line.equals("k")) 
  {
      digitalWrite(8, HIGH);
      Serial.println("Letto ON");
  }
  if (line.equals("l")) 
  {
      digitalWrite(8, LOW);
      Serial.println("Letto OFF");
  }

  //Scrivania
  if (line.equals("m")) 
  {
      digitalWrite(5, HIGH);
      Serial.println("Scrivania ON");
  }
  if (line.equals("n")) 
  {
      digitalWrite(5, LOW);
      Serial.println("Scrivania OFF");
  }

  //Televisione
  if (line.equals("o")) 
  {
      digitalWrite(4, HIGH);
      Serial.println("Televisione ON");
  }
  if (line.equals("p")) 
  {
      digitalWrite(4, LOW);
      Serial.println("Televisione OFF");
  }

  //Accendi Tutto
  if (line.equals("q")) 
  {
      digitalWrite(A0, HIGH);
      digitalWrite(A1, HIGH);
      digitalWrite(A2, HIGH);
      digitalWrite(A3, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      Serial.println(" Luci ON");
  }

  //Spegni Tutto
  if (line.equals("r")) 
  {
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      Serial.println("Luci OFF");
  }

  
  //Apertura Porta
  if (line.equals("s")) 
  {
      stepsPerRevolution = 500;
      for (int i = 0; i < 90; i++) 
      {
          servo1.write(i);
          delay(10); 
          Serial.println("Porta Aperta");
      }
      delay(5000);
      for (int i = 90; i >= 0; i--) 
      {
          servo1.write(i);
          delay(10);
          Serial.println("Porta Chiusa");
      }
  }


   

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Inizio Parte Vocale
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



  
  //Soggiorno
  if (line.equals("aa")) 
  {
      digitalWrite(A0, HIGH);
      Serial.println("Soggiorno ON Vocale");
  }

  if (line.equals("bb")) 
  {
      digitalWrite(A0, LOW);
      Serial.println("Soggiorno OFF Vocale");
  }
  
  //Camera
  if (line.equals("cc")) 
  {
      digitalWrite(A1, HIGH);
      Serial.println("Camera ON Vocale");
  }

  if (line.equals("dd")) 
  {
      digitalWrite(A1, LOW);
      Serial.println("Camera OFF Vocale");
  }
  
  //Cucina
  if (line.equals("ee")) 
  {
      digitalWrite(A2, HIGH);
      Serial.println("Cucina ON Vocale");
  }

  if (line.equals("ff")) 
  {
      digitalWrite(A2, LOW);
      Serial.println("Cucina OFF Vocale");
  }
  
  //Bagno
  if (line.equals("gg")) 
  {
      digitalWrite(A3, HIGH);
      Serial.println("Bagno ON Vocale");
  }

  if (line.equals("hh")) 
  {
      digitalWrite(A3, LOW);
      Serial.println("Bagno OFF Vocale");
  }
  
  //Forno
  if (line.equals("ii")) 
  {
      digitalWrite(9, HIGH);
      Serial.println("Forno ON Vocale");
  }

  if (line.equals("jj")) 
  {
      digitalWrite(9, LOW);
      Serial.println("Forno OFF Vocale");
  }
  
  //Letto
  if (line.equals("kk")) 
  {
      digitalWrite(8, HIGH);
      Serial.println("Letto ON Vocale");
  }

  if (line.equals("ll")) 
  {
      digitalWrite(8, LOW);
      Serial.println("Letto OFF Vocale");
  }
  
  //Scrivania
  if (line.equals("mm")) 
  {
      digitalWrite(5, HIGH);
      Serial.println("Scrivania ON Vocale");
  }

  if (line.equals("nn")) 
  {
      digitalWrite(5, LOW);
      Serial.println("Scrivania OFF Vocale");
  }
  
  //Televisione
  if (line.equals("oo")) 
  {
      digitalWrite(4, HIGH);
      Serial.println("Televisione ON Vocale");
  }

  if (line.equals("pp")) 
  {
      digitalWrite(4, LOW);
      Serial.println("Televisione OFF Vocale");
  }

  
  //ALL ON
  if (line.equals("qq")) 
  {
      digitalWrite(A0, HIGH);
      digitalWrite(A1, HIGH);
      digitalWrite(A2, HIGH);
      digitalWrite(A3, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      Serial.println(" Luci ON Vocale");
  }

  //ALL OFF
  if (line.equals("rr")) 
  {
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      Serial.println("Luci OFF Vocale");
  }


  //Porta 
  if (line.equals("ss")) 
  {
      for (int i = 0; i < 90; i++) 
      {
          servo1.write(i);
          delay(10); 
          Serial.println("Porta Aperta");
      }
      delay(5000);
      for (int i = 90; i >= 0; i--) 
      {
          servo1.write(i);
          delay(10);
          Serial.println("Porta Chiusa");
      }
  }

  

}
