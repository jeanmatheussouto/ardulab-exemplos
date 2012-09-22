#include <IRremote.h>

const int RECV_PIN = 2;

int LED = 13;

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
    irrecv.resume(); // Recebe proximo valor
  }
}


