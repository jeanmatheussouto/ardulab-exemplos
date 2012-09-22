//Programa para controle de LED com LDR
int ledpin = 8;
int ldr = 2;
int val;
void setup () {
  pinMode (ledpin, OUTPUT );
  pinMode (ldr, INPUT );
}
void loop () {
  val = digitalRead(ldr);
  if (val == LOW ) {
    digitalWrite (ledpin, LOW );
  }
  if (val == HIGH ) {
    digitalWrite (ledpin, HIGH );
  }
}


