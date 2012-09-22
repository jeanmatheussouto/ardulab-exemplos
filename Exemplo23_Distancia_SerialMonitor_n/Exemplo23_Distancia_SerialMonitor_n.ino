#include "Ultrasonic.h"
#define echoPin 13
//Pino 13 recebe o pulso do echo
#define trigPin 12
//Pino 12 envia o pulso para gerar o echo
//iniciando a função e passando os pinos
Ultrasonic ultrasonic(12,13);
void setup()
{
  Serial.begin(9600);
  //inicia a porta serial
  pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)
  pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)
}
void loop()
{
  digitalWrite(trigPin, LOW); //seta o pino 12 com um pulso baixo "LOW"
  delayMicroseconds(2);
  // delay de 2 microssegundos
  digitalWrite(trigPin, HIGH); //seta o pino 12 com pulso alto "HIGH"
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // função Ranging, faz a conversão do tempo de
  //resposta do echo em centimetros, e armazena
  //na variavel distancia
  int distancia = (ultrasonic.Ranging(CM));
  Serial.print("Distancia em CM: ");
  Serial.println(distancia);
  delay(1000); //espera 1 segundo para fazer a leitura novamente
}


