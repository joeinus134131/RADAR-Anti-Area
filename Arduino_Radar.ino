/*
 * Development by : IDNMakerspace Algorithm Factory
 * Author : Made Agus Andi Gunawan
 * Last Edited : Jum'at, 8 Januari 2020
 * Reference : Arduino.cc
 */

#include <Servo.h>

const int pinservo = 12;
const int trigPin = 10;
const int echoPin = 11;

long waktu;
int jarak;
Servo IDNServo;

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  IDNServo.attach(pinservo); 
}

void loop() 
{
  //memutar servo sudut 0 - 180 derajat
  for(int sudut=0; sudut<=180; sudut++)
  { 
    IDNServo.write(sudut);
    delay(30);
    jarak = hitungjarak();
    
    Serial.print(sudut); 
    Serial.print(","); 
    Serial.print(jarak); 
    Serial.print(".");
  }

  //memutar servo dari sudut 180 - 0 derajat
  for(int sudut=180; sudut>0; sudut--)
  { 
    IDNServo.write(sudut);
    delay(30);
    jarak = hitungjarak();
    
    Serial.print(sudut);
    Serial.print(",");
    Serial.print(jarak);
    Serial.print(".");
  }
}

//perhitungan jarak 
int hitungjarak()
{ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //fungsi jarak
  waktu = pulseIn(echoPin, HIGH);
  float k = 0.034/2;
  jarak = waktu*k;
  return jarak;
}
