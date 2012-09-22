#include <IRremote.h>
// Inclue a biblioteca IRremote
const int RECV_PIN = 2; //Receptor di IR no pino digital 2
int RELE = 8;
//Relé no pino 8
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
  pinMode(RELE, OUTPUT);
  irrecv.enableIRIn();
  // Inicia o recebimento
}
void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 144){
      //Tecla CH+ do controle remoto
      digitalWrite(RELE, LOW);
    } //Aciona o Relé
    if (results.value == 2192){ //Tecla CH- do controle remoto
      digitalWrite(RELE, HIGH); 
    } //Desliga o Relé
    irrecv.resume(); // Recebe proximo valor
  }
}


