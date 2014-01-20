#include <Ultrasonic.h>

int trig = 13;
int echo = 12;
int distance;
int valeur;



void setup(){
  pinMode(trig, OUTPUT);
  pinMode(echo,INPUT);
  digitalWrite(trig,LOW);
  Serial.begin(9600);

}


void loop() 
{ 
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 
  valeur = pulseIn(echo, HIGH)/65;
  Serial.println(valeur); 
  delay(1000); 
}

