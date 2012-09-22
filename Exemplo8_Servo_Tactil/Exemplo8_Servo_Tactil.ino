#include <Servo.h>

Servo myservo;

int ST1;
//Declara variável ST1
int ST2;
//Declara variável ST2
int CHAVE_1 = 7;
//chave_1 ligada no pin digital 7
int CHAVE_2 = 6;
//chave_2 ligada no pin digital 6

void setup(){
  
  myservo.attach(9,880,2300);
  
  pinMode(CHAVE_1,INPUT);
  //define as chaves como entrada
  
  pinMode(CHAVE_2,INPUT);
  
  myservo.write(70) ;
  //enviando um ângulo de 70 graus, mantém o servo parado
}
void loop() {
  //faz a leitura da chave 1
  ST1 = digitalRead(CHAVE_1);
  //faz a leitura da chave 2
  ST2 = digitalRead(CHAVE_2);
  
  
  if (ST1 == HIGH and ST2==HIGH){
    PARA();
  }
  if (ST1 == LOW and ST2==HIGH){
    GIRA();
  }
  if (ST1 == HIGH and ST2==LOW){
    VOLTA();
  }
}
void GIRA() {
  myservo.write(180); // gira o servo
  delay(1000);
  PARA();
}
void PARA() {
  myservo.write(70); // pára o servo
  delay(5);
}
void VOLTA() {
  myservo.write(0); // gira o servo sentido contrário
  delay(1000);
  PARA();
}


