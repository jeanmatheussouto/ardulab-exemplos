#include <Servo.h>

Servo myservo;
int pin = 9;
int flag = 0;
int i;
int char_in;
void setup()
{
  pinMode(pin,OUTPUT);
  Serial.begin(9600);
  colocaMenu();
}
void loop(){
  //piscaled() ;
  if(Serial.available() > 0 ) {
    char_in = Serial.read() ;
    if(char_in != -1) {
      Serial.println(char_in) ;
      switch (char_in) {
      case '1':
        myservo.attach(pin) ;
        myservo.write(180) ;
        Serial.println("Para o servo motor") ;
        break;
      case '2':
        myservo.attach(pin,880,2400) ;
        myservo.write(180) ;
        Serial.println("Anda para TRAZ") ;
        break;
      case '3':
        myservo.attach(pin,880,2400) ;
        myservo.write(0) ;
        Serial.println("ANDA PARA FRENTE") ;
        break;
      default :
        Serial.println("Opcao Invalida") ;
        break;
      }
    }
  }
}
void colocaMenu() {
  Serial.println("Teste de motor servo") ;
  Serial.println("Selecione :") ;
  Serial.println("1 - PARAR O MOTOR") ;
  Serial.println("2 - ANDA PARA TRAZ") ;
  Serial.println("3 - ANDA PARA FRENTE") ;
  Serial.println("Opcao ? ") ;
}


