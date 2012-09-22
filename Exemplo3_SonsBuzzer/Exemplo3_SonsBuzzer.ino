/*
Melodia
 D8 - Pino Digital 8 ligado ao BUZZER
 */
#include "pitches.h"
// notas da melodia:
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};
// durações nota: 4 nota = trimestre, nota 8 = oitava, etc:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };
void setup() {
  // iteração sobre as notas da melodia:
  //for (int thisNote = 0; thisNote < 8; thisNote++) {
    // calcular a duração da nota, em um segundo
    // dividido pelo tipo de nota.
    // por exemplo semínima = 1000 / 4, colcheia = 1000 / 8, etc
    //int noteDuration = 1000/noteDurations[thisNote];
    //tone(8, melody[thisNote],noteDuration);
    // para distinguir as notas, definir um tempo mínimo entre elas.
    // duração da nota + 30% parece funcionar bem:
    //int pauseBetweenNotes = noteDuration * 1.30;
    //delay(pauseBetweenNotes);
    // parar a reprodução de tom:
    //noTone(8);
 // }
}
void loop() {
  // para não repetir a melodia.
  // iteração sobre as notas da melodia:
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // calcular a duração da nota, em um segundo
    // dividido pelo tipo de nota.
    // por exemplo semínima = 1000 / 4, colcheia = 1000 / 8, etc
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);
    // para distinguir as notas, definir um tempo mínimo entre elas.
    // duração da nota + 30% parece funcionar bem:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // parar a reprodução de tom:
    noTone(8);
  }
  delay(3000);
}


