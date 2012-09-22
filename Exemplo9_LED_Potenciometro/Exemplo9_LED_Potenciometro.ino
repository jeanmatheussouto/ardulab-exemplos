int potPin = 5;
int ledPin = 10;
// pino de entrada para o potenciômetro
// pino de saida para o LED
void setup()
{
  pinMode(ledPin, OUTPUT);
}
// declara ledPin como SAIDA
void loop() // ledPin em on
{ // Espera por um tempo “potPin”
  digitalWrite(ledPin, HIGH); 
  delay(analogRead(potPin)); 
  digitalWrite(ledPin, LOW); // ledPin em off
  delay(analogRead(potPin)); // Espera por um tempo “potPin”
}


