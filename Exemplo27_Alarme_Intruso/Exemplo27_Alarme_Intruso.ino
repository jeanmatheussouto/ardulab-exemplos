//Alarme de intruso com sensor de ultrasom
int cm;
int trig = 6;
int echo = 7;
long microseconds;
int temp;
int del = 250;
// Duração do Tom
int lowrange = 2000; // Valor mais baixo da freqencia usada
int highrange = 4000; // Frequencia mais alta
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(8, OUTPUT); // Buzzer porta 8
}
void loop() {
  long duration, cm;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  duration = pulseIn(echo, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
  if (cm <= 250){
    alarme();
  } //Objeto a menos de 250cm
  else {
    digitalWrite(8,LOW);
  }
}
long microsecondsToCentimeters(long microseconds) { 
  return microseconds / 29 / 2;
}
void alarme() {
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


