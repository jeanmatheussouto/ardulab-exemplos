/*
SENSOR DE TEMPERATURA
 Este programa aciona um servo de acordo com a temperatura
 */
#include <DallasTemperature.h>
DallasTemperature tempSensor;
#include <MegaServo.h> //Inclue a biblioteca MegaServos
#define NBR_SERVOS 12 // Numero de Servos ligados
#define FIRST_SERVO_PIN 3
MegaServo Servos[NBR_SERVOS] ;
int temp;
void setup() { // inicializando entradas e saídas Servos[1].attach(7,880,2300); //Servo na porta digital 7
  Servos[1].write(70);
  delay(15);
  Serial.begin(9600); // inicializa a porta serial
  tempSensor.begin(12); // sensor ligado na porta digital 12
  Serial.println("Temperatura Atual: ");
}
void loop() {
  Serial.print(tempSensor.getTemperature());
  // envia para o monitor serial.
  Serial.print("C");
  Serial.println(" ");
  //Serial.println(tempSensor.getTemperature());
  if (tempSensor.getTemperature() < 25)
  {
    Servos[1].write(0);
    delay(30);
  }
  if (tempSensor.getTemperature() > 25 and tempSensor.getTemperature() < 30) {
    Servos[1].write(70);
    delay(30);
  }
  if (tempSensor.getTemperature() > 30) {
    Servos[1].write(180);
    delay(30);
  }
}


