//Apertura Porta con sensore Touch.

//Autore --> Alessio_Borgi
//Classe --> 5AINF
//Copyright © 2020 Alessio Borgi


#include <Servo.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
const int servoPin = 3; // Servo pin
const int touchPin = 7; // Pushtouch pin
int ledPin = 5;
int touchState = 0;
int directionState = 0;
Servo myservo;
int pos = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Sensore Tattile");
  lcd.setCursor(0, 1);
  lcd.print("Door Lock System");
  myservo.attach(3);
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  touchState = digitalRead(touchPin);
  if (directionState == 0) 
  {
    if (touchState == HIGH) 
    {
      directionState = 1;
      for (pos = 0; pos < 90; pos += 1)
        digitalWrite(ledPin, 1);
      lcd.clear();
      lcd.print("Status: Unlocked");
      lcd.setCursor(0, 1);
      lcd.print("Touch to Lock");
      {
        myservo.write(pos);
        delay(15); // waits 15ms to reach the position
      }

      //Dopo 5 sec si chiude
      delay(5000);
      
      directionState = 0;

      for (pos = 90; pos >= 1; pos -= 1)
        digitalWrite(ledPin, 0);
      lcd.clear();
      lcd.print("Status: Locked");
      lcd.setCursor(0, 1);
      lcd.print("Touch to Unlock");
      {
        myservo.write(pos);
        delay(15);
      }
      
    }

  } 
  
  else if (directionState == 1) 
  {
    if (touchState == HIGH) 
    {
      directionState = 0;

      for (pos = 90; pos >= 1; pos -= 1)
        digitalWrite(ledPin, 0);
      lcd.clear();
      lcd.print("Status: Locked");
      lcd.setCursor(0, 1);
      lcd.print("Touch to Unlock");
      {
        myservo.write(pos);
        delay(15);
      }
    }
  }
}
