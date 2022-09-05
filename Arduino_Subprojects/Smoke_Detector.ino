//Smoke Detector

//Autore --> Alessio_Borgi
//Classe --> 5AINF
//Copyright © 2020 Alessio Borgi


#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int smokeA0 = A3;
int buzzer=8;
int sensorThres = 250;

void setup()
{
lcd.begin(16,2);                

  pinMode(smokeA0, INPUT);                             
  Serial.begin(9600);

}

void loop() {
  int analogSensor = analogRead(smokeA0);
  
  Serial.print("Pin A3: ");
  Serial.println(analogSensor);
  lcd.setCursor(0, 0);
  lcd.print("Smoke Level:");
  lcd.print(analogSensor-50);
  // Checks if it has reached the threshold value
  if (analogSensor-50 > sensorThres)
  {
    lcd.setCursor(0, 2);
    lcd.print("Alert....!!!");
    digitalWrite(12, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(12, HIGH);
    lcd.setCursor(0, 2);
    lcd.print(".....Normal.....");
    noTone(buzzer);
  }
  delay(500);
  lcd.clear();
}
