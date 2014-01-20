#include <Ultrasonic.h>

int trig = 2;
int echo = 3;
int distance;
int valeur;
int time;

int moteurDavant = 13;
int moteurDarriere = 12;
int moteurGavant = 10;
int moteurGarriere = 9;

int enable1 = 6;
int enable2 = 5;




void setup(){
  pinMode(moteurDavant, OUTPUT);
  pinMode(moteurDarriere, OUTPUT);
  pinMode(moteurGavant, OUTPUT);
  pinMode(moteurGarriere, OUTPUT);
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);

  digitalWrite(moteurDavant, LOW);
  digitalWrite(moteurDarriere, LOW);
  digitalWrite(moteurGavant, LOW);
  digitalWrite(moteurGarriere, LOW);
  digitalWrite(enable1, HIGH);
  digitalWrite(enable2, HIGH);
  
   pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trig, LOW);
  Serial.begin(9600);

}


void loop(){
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  valeur = pulseIn(echo, HIGH)/60;
  Serial.println(valeur);
  
  if(valeur<20){
    arret();
    tournerG();
    arret();
  }
  else{
  avancer();
  }
}




void avancer(){
  digitalWrite(enable1, HIGH);
  digitalWrite(enable2, HIGH);
  digitalWrite(moteurDavant, HIGH);
  digitalWrite(moteurDarriere, LOW);
  digitalWrite(moteurGavant, HIGH);
  digitalWrite(moteurGarriere, LOW);
}
void arret(){
  digitalWrite(enable1, LOW);
  digitalWrite(enable2, LOW);
  delay(500);
}
void  tournerD(){
  digitalWrite(enable1, HIGH);
  digitalWrite(enable2, HIGH);
  digitalWrite(moteurDavant, LOW);
  digitalWrite(moteurDarriere, HIGH);
  digitalWrite(moteurGavant, HIGH);
  digitalWrite(moteurGarriere, LOW);
  

}
void tournerG(){
  digitalWrite(enable1, HIGH);
  digitalWrite(enable2, HIGH);
  digitalWrite(moteurDavant, HIGH);
  digitalWrite(moteurDarriere, LOW);
  digitalWrite(moteurGavant, LOW);
  digitalWrite(moteurGarriere, HIGH);
  delay(1200);
  

}



