#include <IRremote.h>

const int RECV_PIN = 2;

int LED = 7;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true);
}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    if (results.value == 144){
      digitalWrite(LED, HIGH);
    }
    if (results.value == 2192){
      digitalWrite(LED, LOW); 
    }
    irrecv.resume(); // Recebe proximo valor
  }
}


