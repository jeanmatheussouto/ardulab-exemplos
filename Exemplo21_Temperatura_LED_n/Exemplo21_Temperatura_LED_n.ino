/*
SENSOR DE TEMPERATURA
 - Este programa acende o led azul para temperatura abaixo de 25 graus
 - Acende o led amarelo para temperaturas entre 25 e 30 graus
 - Acende o led vermelho para temperaturas maiores que 30 graus
 */
#include <DallasTemperature.h>
DallasTemperature tempSensor;
int led_azul = 8;
//led azul no pino 8
int led_amar = 9;
//led amarelo no pino 9
int led_verm = 10;
//led vermelho no pino 10
int temp;
void setup() { // inicializando entradas e saídas
  LED Azul acende para temperaturas menores que 25°
    LED Amarelo acende para temperaturas entre 25° e 30°
    LED Vermelho acende para temperaturas maiores que 30°
Passos:
    pinMode(led_azul, OUTPUT);
  pinMode(led_amar, OUTPUT);
  pinMode(led_verm, OUTPUT);
  Serial.begin(9600); // inicializa a porta serial
  tempSensor.begin(12); // sensor ligado na porta digital 12
  Serial.println("Temperatura Atual: ");
}
void loop() {
  Serial.print(tempSensor.getTemperature());
  // envia para o monitor serial.
  Serial.print("C");
  Serial.println();
  Serial.print(tempSensor.getTemperature());
  if (tempSensor.getTemperature() < 25)
  {
    digitalWrite(led_azul, HIGH);
    //verifica se a temperatura é menor que 20 graus
    digitalWrite(led_amar, LOW);
    digitalWrite(led_verm, LOW);
  }
  if (tempSensor.getTemperature() > 25 and tempSensor.getTemperature() < 30) {
    digitalWrite(led_azul, LOW);
    //verifica se a temperatura é menor que 20 graus
    digitalWrite(led_amar, HIGH);
    digitalWrite(led_verm, LOW);
  }
  if (tempSensor.getTemperature() > 30) {
    digitalWrite(led_azul, LOW);
    //verifica se a temperatura é menor que 20 graus
    digitalWrite(led_amar, LOW);
    digitalWrite(led_verm, HIGH);
  }
}


