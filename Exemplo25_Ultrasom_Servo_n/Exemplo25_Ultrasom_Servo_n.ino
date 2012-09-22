#include <MegaServo.h> //Inclue a biblioteca MegaServos
#define NBR_SERVOS 12 // Numero de Servos ligados. Maximo de 48 arduino MEGA, 12 para outros arduinos
#define FIRST_SERVO_PIN 3
MegaServo Servos[NBR_SERVOS] ;
// Obs: Se você não tiver esta biblioteca faça o download no site: www.robotic.com.br
int cm;
int trig = 8;
int echo = 7;
long microseconds;
void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Servos[1].attach(3,880,2400);
}
void loop() {
  long duration, cm;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  duration = pulseIn(echo, HIGH);
  cm = microsecondsToCentimeters(duration);
  if (cm <= 20){
    gira();
  }
  //Objeto a menos de 20cm o servo gira em um sentido
  if (cm > 20 and cm < 60){
    volta();
  } //Objeto entre 20 e 60cm servo gira em sentido contrário
  if (cm >= 60){
    pare();
  }
  // Objetos a mais de 60cm servo mantém parado
}
long microsecondsToCentimeters(long microseconds) { 
  return microseconds / 29 / 2;
}
void gira() {
  Servos[1].write(180);
  delay(300);
}
void pare() {
  Servos[1].write(70);
  delay(300);
}
// ângulo de 70 graus faz o servo parar
void volta() {
  Servos[1].write(0);
  delay(300);
}


