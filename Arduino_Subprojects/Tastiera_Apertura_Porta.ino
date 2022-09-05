//Tastiera Apertura Porta con LCD Display

//Autore --> Alessio_Borgi
//Classe --> 5AINF
//Copyright © 2020 Alessio Borgi

#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

Servo myservo;
int pos = 90; // LCD Connections
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
const byte rows = 4;
const byte cols = 3;

char key[rows][cols] = 
{
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[rows] = {1, 2, 3, 4};
byte colPins[cols] = {5, 6, 7};
Keypad keypad = Keypad(makeKeymap(key), rowPins, colPins, rows, cols);
char* password = "4567";
int currentposition = 0;
int redled = 10;
int greenled = 11;
int buzz = 8;
int invalidcount = 12;



void setup()
{

  displayscreen();
  Serial.begin(9600);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(buzz, OUTPUT);
  myservo.attach(9); //SERVO ATTACHED//

  lcd.begin(16, 2);

}

void loop()
{
  if ( currentposition == 0)
  {
    displayscreen();

  }
  int l ;
  char code = keypad.getKey();
  if (code != NO_KEY)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PASSWORD:");
    lcd.setCursor(7, 1);
    lcd.print(" ");
    lcd.setCursor(7, 1);
    for (l = 0; l <= currentposition; ++l)
    {

      lcd.print("*");
      keypress();
    }

    if (code == password[currentposition])
    {
      ++currentposition;
      if (currentposition == 4)
      {

        unlockdoor();
        currentposition = 0;

      }

    }

    else
    {
      ++invalidcount;
      incorrect();
      currentposition = 0;

    }
    if (invalidcount == 5)
    {

      ++invalidcount;
      torture1();

    }
    if (invalidcount == 8)
    {
      torture2();
    }

  }
  // LOOP ENDS!!!//
}

//********Funzione Apertura Porta!!!!***********//

void unlockdoor()
{
  delay(900);

  lcd.setCursor(0, 0);
  lcd.println(" ");
  lcd.setCursor(1, 0);
  lcd.print("AUTORIZZATO");
  lcd.setCursor(1, 1);
  lcd.println("BENVENUTO!!!");
  lcd.setCursor(15, 1);
  lcd.println(" ");
  lcd.setCursor(16, 1);
  lcd.println(" ");
  lcd.setCursor(14, 1);
  lcd.println(" ");
  lcd.setCursor(13, 1);
  lcd.println(" ");
  unlockbuzz();

  for (pos = 90; pos <= 180; pos += 1) // Va da 180 gradi a 90 gradi
  {
    myservo.write(pos); 
    delay(15); 
  }
  delay(2000);



  delay(1000);
  counterbeep();

  delay(1000);

  for (pos = 180; pos >= 90; pos -= 1) // Va da 90 gradi a 180 gradi
  { 
    myservo.write(pos); 
    delay(15);


    currentposition = 0;

    lcd.clear();
    displayscreen();

  }
}

//************Funzione Codice Sbagliato********//

void incorrect()
{
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CODICE");
  lcd.setCursor(6, 0);
  lcd.print("INCORRETTO");
  lcd.setCursor(15, 1);
  lcd.println(" ");
  lcd.setCursor(4, 1);
  lcd.println("VAI VIA!!!");

  lcd.setCursor(13, 1);
  lcd.println(" ");
  Serial.println("NON SEI AUTORIZZATO");
  digitalWrite(redled, HIGH);
  digitalWrite(buzz, HIGH);
  delay(3000);
  lcd.clear();
  digitalWrite(redled, LOW);
  digitalWrite(buzz, LOW);
  displayscreen();
}


//************** CLEAR THE SCREEN!!!*************//

void clearscreen()
{
  lcd.setCursor(0, 0);
  lcd.println(" ");
  lcd.setCursor(0, 1);
  lcd.println(" ");
  lcd.setCursor(0, 2);
  lcd.println(" ");
  lcd.setCursor(0, 3);
  lcd.println(" ");
}


//**************KEYPRESS********************//

void keypress()
{



  digitalWrite(buzz, HIGH);
  delay(50);
  digitalWrite(buzz, LOW);
}


//********DISPALAY FUNCTION!!!*************//

void displayscreen()
{

  lcd.setCursor(0, 0);
  lcd.println("DIGITA IL CODICE");
  lcd.setCursor(1 , 1);

  lcd.println("PER ENTRARE");
}


//*************** ARM SERVO***********//

void armservo()
{

  for (pos = 90 ; pos <= 180; pos += 1)
  {
    myservo.write(pos);
    delay(15);
  }
  delay(5000);

  for (pos = 180; pos >= 90; pos -= 1)
  {
    myservo.write(pos);
  }

}


//**********UNLOCK BUZZ*************//

void unlockbuzz()
{

  digitalWrite(buzz, HIGH);
  delay(80);
  digitalWrite(buzz, LOW);
  delay(80);
  digitalWrite(buzz, HIGH);
  delay(80);
  digitalWrite(buzz, LOW);
  delay(200);
  digitalWrite(buzz, HIGH);
  delay(80);
  digitalWrite(buzz, LOW);
  delay(80);
  digitalWrite(buzz, HIGH);
  delay(80);
  digitalWrite(buzz, LOW);
  delay(80);
}


//**********COUNTER BEEP**********//

void counterbeep()
{
  delay(1200);
  lcd.clear();
  digitalWrite(buzz, HIGH);
  lcd.setCursor(2, 15);
  lcd.println(" ");
  lcd.setCursor(2, 14);
  lcd.println(" ");
  lcd.setCursor(2, 0);
  delay(200);
  lcd.println("CHIUSURA PORTA IN:");
  lcd.setCursor(4, 1);
  lcd.print("5");
  delay(200);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.println("CHIUSURA PORTA IN:");
  digitalWrite(buzz, LOW);
  delay(1000);
  //2
  digitalWrite(buzz, HIGH);
  lcd.setCursor(2, 0);
  lcd.println("CHIUSURA PORTA IN:");
  lcd.setCursor(4, 1); //2
  lcd.print("4");
  delay(100);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.println("CHIUSURA PORTA IN:");
  digitalWrite(buzz, LOW);
  delay(1000);
  //3
  digitalWrite(buzz, HIGH);
  lcd.setCursor(2, 0);
  lcd.println("CHIUSURA PORTA IN:");
  lcd.setCursor(4, 1); //3
  lcd.print("3");
  delay(100);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.println("CHIUSURA PORTA IN:");
  digitalWrite(buzz, LOW);
  delay(1000);
  //4
  digitalWrite(buzz, HIGH);
  lcd.setCursor(2, 0);
  lcd.println("CHIUSURA PORTA IN:");
  lcd.setCursor(4, 1); //4
  lcd.print("2");
  delay(100);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.println("CHIUSURA PORTA IN:");
  digitalWrite(buzz, LOW);
  delay(1000);
  //
  digitalWrite(buzz, HIGH);
  lcd.setCursor(4, 1);
  lcd.print("1");
  delay(100);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.println("CHIUSURA PORTA IN::");
  digitalWrite(buzz, LOW);
  delay(1000);
  //5
  digitalWrite(buzz, HIGH);
  delay(40);
  digitalWrite(buzz, LOW);
  delay(40);
  digitalWrite(buzz, HIGH);
  delay(40);
  digitalWrite(buzz, LOW);
  delay(40);
  digitalWrite(buzz, HIGH);
  delay(40);
  digitalWrite(buzz, LOW);
  delay(40);
  digitalWrite(buzz, HIGH);
  delay(40);
  digitalWrite(buzz, LOW);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("BLOCCO IN");
  delay(500);
  lcd.setCursor(12, 0);
  lcd.print(".");
  delay(500);
  lcd.setCursor(13, 0);
  lcd.print(".");
  delay(500);
  lcd.setCursor(14, 0);
  lcd.print(".");
  delay(400);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("BLOCCATO!");
  delay(440);
}


//*********TORTURE1***********//
void torture1()
{
  delay(1000);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("ASPETTA ");
  lcd.setCursor(5, 1);
  lcd.print("15 SECONDI");
  digitalWrite(buzz, HIGH);
  delay(15000);
  digitalWrite(buzz, LOW);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("LOL...");
  lcd.setCursor(1, 1);
  lcd.print(" AHAHAHAHHAHA??");
  delay(3500);
  lcd.clear();

}
//*****TORTURE2*****//
void torture2()
{
  delay(1000);
  lcd.setCursor(1, 0);
  lcd.print(" ");
  lcd.setCursor(2, 0);
  lcd.print("ASCOLTA");
  lcd.setCursor(0, 1);
  lcd.print("IL RUMORE ");
  delay(1500);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print(" ASPETTA PER");
  lcd.setCursor(4, 1);
  lcd.print(" 1 MINUTO");
  digitalWrite(buzz, HIGH);
  delay(55000);
  counterbeep();
  lcd.clear();
  digitalWrite(buzz, LOW);
  lcd.setCursor(2, 0);
  lcd.print("ANCORA VUOI ENTRARE");
  lcd.setCursor(1, 1);
  lcd.print("SEI TESTARDO??");
  delay(2500);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Ha Ha Ha Ha");
  delay(1700);
  lcd.clear();
}
