//define pinos.
#define irLedPin 4
// lED infrared no pino 4
#define irSensorPin 5
// Sensor infrared no pino 5
int irRead(int readPin, int triggerPin);
//função protótipo
int LED = 7;
void setup()
{
  pinMode(irSensorPin, INPUT);
  pinMode(irLedPin, OUTPUT);
  pinMode(LED, OUTPUT);
  delay(100);
}
void loop()
{
  if (irRead(irSensorPin, irLedPin) == 0){
    digitalWrite(LED, HIGH);
  }
  if (irRead(irSensorPin, irLedPin) == 1){
    digitalWrite(LED, LOW);
  }
  delay(10); //Aguarda o envio
}
int irRead(int readPin, int triggerPin)
{
  //um período em 38.5khZ é de aproximadamente 26 microssegundos, ciclos int = 38
  int halfPeriod = 13;
  //26 microssegundos * 38 é mais ou menos um milissegundo
  int cycles = 38;
  int i;
  for (i=0; i <=cycles; i++)
  {
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(halfPeriod - 1);
    // - 1 para compensar a sobrecarga digitaWrite
  }
  return digitalRead(readPin);
}


