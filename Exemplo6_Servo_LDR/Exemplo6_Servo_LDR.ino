//Programa para controlar o servo com LDR
#include <Servo.h>
Servo myservo;
int servo = 10;
int ldr = 2;
int val;
void setup(){
  pinMode(servo,OUTPUT);
  pinMode(ldr,INPUT);
  myservo.attach(servo,880,2300) ; //Inicia com o servo parado
  myservo.write(70);
  delay(300);
}
void loop() {
  val = digitalRead(ldr); //verifica o ldr e guarda seu status
  if (val == LOW ) {
    myservo.attach(servo,880,2300) ; //Pára o servo
    myservo.write(70);
    delay(3000);
  }
//Passos:
  if (val == HIGH ) {
    myservo.attach(servo,880,2300) ; // aciona o servo
    myservo.write(180) ;
    delay(300);
  }
}


