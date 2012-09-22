#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// ligado na porta 8
#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(void) {
  // initialize entradas e saídas
  // inicializa a porta serial
  lcd.begin(8, 2);
  sensors.begin(); // sensor ligado na porta digital 6
  lcd.print("Temp.:"); // envia a mensagem para o LCD.
}
void loop(void) {
  // Pega temperatura e envia para o monitor serial.
  lcd.setCursor(0,1); //Posiciona cursor na segunda linha
  lcd.print(sensors.getTempCByIndex(0));
  lcd.print("C");
}


