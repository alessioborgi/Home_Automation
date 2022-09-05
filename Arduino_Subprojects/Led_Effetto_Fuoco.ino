// ARDUINO LED EFFETTO FUOCO O FIAMMA.

//Autore --> Alessio_Borgi
//Classe --> 5AINF
//Copyright © 2020 Alessio Borgi

int Tempo = 140;
int TmpRandom = 150;
int Giallo_1 = 3;   
int Giallo_2 = 5;
int Giallo_3 = 7;
int Giallo_4 = 9;
int Giallo_5 = 11;
int Rosso_1 = 4;
int Rosso_2 = 6;
int Rosso_3 = 8;
int Rosso_4 = 10;
int Rosso_5 = 12;

void setup()   
{
    pinMode(Giallo_1, OUTPUT); 
    pinMode(Rosso_1, OUTPUT);    
    pinMode(Giallo_2, OUTPUT);
    pinMode(Rosso_2, OUTPUT);
    pinMode(Giallo_3, OUTPUT);
    pinMode(Rosso_3, OUTPUT);
    pinMode(Giallo_4, OUTPUT);
    pinMode(Rosso_4, OUTPUT);
    pinMode(Giallo_5, OUTPUT);
    pinMode(Rosso_5, OUTPUT);

}
void loop() 
{
analogWrite(Giallo_1, random(TmpRandom)+Tempo);   
analogWrite(Rosso_1, random(TmpRandom)+Tempo);      
analogWrite(Giallo_2, random(TmpRandom)+Tempo);
analogWrite(Rosso_2, random(TmpRandom)+Tempo); 
analogWrite(Giallo_3, random(TmpRandom)+Tempo);
analogWrite(Rosso_3, random(TmpRandom)+Tempo); 
analogWrite(Giallo_4, random(TmpRandom)+Tempo);
analogWrite(Rosso_4, random(TmpRandom)+Tempo); 
analogWrite(Giallo_5, random(TmpRandom)+Tempo);
analogWrite(Rosso_5, random(TmpRandom)+Tempo); 
delay(random(100));    
}
