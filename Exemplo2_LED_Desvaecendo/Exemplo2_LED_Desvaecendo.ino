/* Fading (Desvanecimento do Led)
 * Este exemplo mostra como a desvanecer um LED usando a função analogWrite ().
 * LED ligado ao pin 9 PWM
 */
int ledPin = 9;
// LED no digital pin 9
void setup() { 
}
void loop() {
  // fade in de min a max em incrementos de 5 pontos:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {
    // define o valor (escala de 0 a 255):
    analogWrite(ledPin, fadeValue);
    // espera por 30 milésimos de segundo para ver o efeito de escurecimento
      delay(30);
  }
// fade out de Max para min com incrementos de 5 pontos:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
    // define o valor (escala de 0 a 255):
    analogWrite(ledPin, fadeValue);
    // espera por 30 milésimos de segundo para ver o efeito de escurecimento
      delay(30);
  }
}


