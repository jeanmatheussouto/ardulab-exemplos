#include <OneWire.h>
#include <DallasTemperature.h>

// ligado na porta 2
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

int temp;
int del = 250;
// Duração do Tom
int lowrange = 2000; // Valor mais baixo da freqencia usada
int highrange = 4000; // Frequencia mais alta

void setup(void){
  Serial.begin(9600);

  sensors.begin();
  
  pinMode(8, OUTPUT); // Buzzer porta 8
}

void loop() {
  Serial.print("Requisitando a temperatura...");
  
  sensors.requestTemperatures(); // Send the command to get temperatures
  
  Serial.println("PRONTO..");
  
  
  Serial.print("A temperatura eh: ");
  
  Serial.println(sensors.getTempCByIndex(0)); 
  
  
  if (sensors.getTempCByIndex(0) > 30){
    alarme();
  }
}

void alarme() {
  Serial.print("alarme");
  for (int a = lowrange; a<=highrange; a++)
  {
    tone (8, a, del);
  }
  // Redução dos tons
  for (int a = highrange; a>=lowrange; a--)
  {
    tone (8, a, del);
  }
}


