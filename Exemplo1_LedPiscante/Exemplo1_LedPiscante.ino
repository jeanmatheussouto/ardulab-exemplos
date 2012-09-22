/*
* LED PISCANTE
* Liga e Desliga um LED conectado a um pino digital 8
* em intervalos de 1 segundos.
*/

int ledPin = 8; //Led conectado ao pino digital 8

void setup(){
  pinMode(ledPin,OUTPUT); //configura pino digital como saida
}

void loop(){
  digitalWrite(ledPin,HIGH); //liga led
  delay(1000);
  digitalWrite(ledPin,LOW); //liga led
  delay(1000);
  
}
