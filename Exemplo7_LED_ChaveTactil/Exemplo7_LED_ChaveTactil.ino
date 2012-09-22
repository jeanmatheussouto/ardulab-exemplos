int chave = 2;
int led = 8;
int State = 0;
// Chave táctil no pin 7
// LED no pino 8
// variável para armazenar o estado da chave
void setup() {
  pinMode(led, OUTPUT);
  pinMode(chave, INPUT);
}
void loop(){
  State = digitalRead(chave);
  if (State == HIGH) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}


