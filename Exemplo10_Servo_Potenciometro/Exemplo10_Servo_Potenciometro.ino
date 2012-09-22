// Biblioteca que permite controlar mais facilmete os Servos
#include <Servo.h> 

// Criação de um objecto que permitira controlar o servo
Servo servo1; 
// Declaração da variavel para o pino que vai ler o valor do potenciometro, neste caso é o pino 5
//analogico 5 
int pinopot = 5; 
int valor; 
void setup(){
  servo1.attach(10);
}
// Declaração da variavel onde vai ser colocado o valor lido do pino analogico 0
// Porta onde ira ser ligado o servo
void loop()
{
  valor = analogRead(pinopot);
  valor = map(valor, 0, 1023, 0, 179);
  servo1.write(valor);
  delay(1);
}


