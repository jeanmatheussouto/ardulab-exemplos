#include "Wire.h"
#define DS1307_I2C_ADDRESS 0x68
#include <MegaServo.h> //Inclue a biblioteca MegaServos
#define NBR_SERVOS 12 // Numero de Servos ligados. Maximo de 48 arduino MEGA, 12 para outros
arduinos
#define FIRST_SERVO_PIN 3
MegaServo Servos[NBR_SERVOS] ;
// Convert normal decimal numbers to binary coded decimal
// Ligar o SDA ao pin4 da entrada analógica e SCL ao pin5 da entrada analógica
int LED = 13; //led ligado ao pin 13
byte decToBcd(byte val)
{
  return ( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return ( (val/16*10) + (val%16) );
}
void setDateDs1307(byte second, // 0-59
byte minute, // 0-59
byte hour, // 1-23
byte dayOfWeek, // 1-7
byte dayOfMonth, // 1-28/29/30/31
byte month, // 1-12
byte year) // 0-99
{
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.send(0);
  Wire.send(decToBcd(second)); // 0 to bit 7 starts the clock
  Wire.send(decToBcd(minute));
  Wire.send(decToBcd(hour)); // If you want 12 hour am/pm you need to set
  // bit 6 (also need to change readDateDs1307)
  Wire.send(decToBcd(dayOfWeek));
  Wire.send(decToBcd(dayOfMonth));
  Wire.send(decToBcd(month));
  Wire.send(decToBcd(year));
  Wire.endTransmission();
}
// Gets the date and time from the ds1307
void getDateDs1307(byte *second,
byte *minute,
byte *hour,
byte *dayOfWeek,
byte *dayOfMonth,
byte *month,
byte *year)
{
  // Reset the register pointer
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.send(0);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_I2C_ADDRESS, 7);
  // A few of these need masks because certain bits are control bits
  *second = bcdToDec(Wire.receive() & 0x7f);
  *minute = bcdToDec(Wire.receive());
  *hour = bcdToDec(Wire.receive() & 0x3f); // Need to change this if 12 hour am/pm
  *dayOfWeek = bcdToDec(Wire.receive());
  *dayOfMonth = bcdToDec(Wire.receive());
  *month = bcdToDec(Wire.receive());
  *year = bcdToDec(Wire.receive());
}
void setup() //Registrando a data atual no RTC
{
  //byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  Servos[1].attach(3,880,2300); //Servo na porta digital 3
  Servos[1].write(70);
  delay(15);
  Wire.begin();
  Serial.begin(9600);
}
void loop()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  getDateDs1307(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  Serial.print("Sao: ");
  Serial.print(hour, DEC);
  Serial.print(":");
  Serial.print(minute, DEC);
  Serial.print(":");
  Serial.print(second, DEC);
  Serial.print(" ");
  Serial.print(dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(month, DEC);
  Serial.print("/20");
  Serial.println(year, DEC);
  // As 8:45h o servo será acionado e as 8:47 desligado
  if (hour == 8 and minute >= 45) { 
    Servos[1].write(180);
  }
  if (hour == 8 and minute >= 47) { 
    Servos[1].write(70);
  }
  //Serial.println(dayOfWeek);
  delay(1000);
}


