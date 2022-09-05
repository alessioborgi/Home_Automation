//Alcohol Analyzer

//Autore --> Alessio_Borgi
//Classe --> 5AINF
//Copyright © 2020 Alessio Borgi


#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int ledPin = 10;
int sensorPin = A0;
int value;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);
}
void loop()
{
  int Value = analogRead(sensorPin);
  value = analogRead(A0);
  lcd.print("Alcohol Lev.:");
  lcd.print(value - 50);
  Serial.print(value);
  if (value - 50 > 100 && value - 50 < 125)
  {
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0, 2);
    lcd.print("Alert Level 1 !");
    Serial.print ("Alert Level 1 !");
  }
  else if (value - 50 >= 125 && value - 50 < 150)
  {
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0, 2);
    lcd.print("Alert Level 2 !");
    Serial.print ("Alert Level 2 !");
  }
  else if (value - 50 >= 150 && value - 50 < 175)
  {
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0, 2);
    lcd.print("Alert Level 3 !");
    Serial.print ("Alert Level 3 !");
  }
  else if (value - 50 >= 175 && value - 50 < 200)
  {
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0, 2);
    lcd.print("Alert Level 4 !");
    Serial.print ("Alert Level 4 !");
  }
  else if (value - 50 >= 200 && value - 50 < 250)
  {
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0, 2);
    lcd.print("Alert Level 5 !");
    Serial.print ("Alert Level 5 !");
  }
  else if (value - 50 >= 250)
  {
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0, 2);
    lcd.print("Alcohol Coma!");
    Serial.print ("Alcohol Coma!");
  }
  else {
    digitalWrite(ledPin, LOW);
    lcd.setCursor(0, 2);
    lcd.print(".....Normal.....");
    Serial.print("Normal");
  }

  delay(500);
  lcd.clear();
}
