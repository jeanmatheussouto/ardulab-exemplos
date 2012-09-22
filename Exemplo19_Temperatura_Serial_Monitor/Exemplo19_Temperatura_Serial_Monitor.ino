#include <OneWire.h>
#include <DallasTemperature.h>

// ligado na porta 2
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

void setup(void){
  Serial.begin(9600);

  sensors.begin();
}

void loop(void){ 
  
  Serial.print("Requisitando a temperatura...");
  
  sensors.requestTemperatures(); // Send the command to get temperatures
  
  Serial.println("PRONTO..");
  
  
  Serial.print("A temperatura eh: ");
  
  Serial.println(sensors.getTempCByIndex(0));  
}
