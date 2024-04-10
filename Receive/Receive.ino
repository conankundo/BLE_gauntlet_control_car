// Code mạch nhận
char m=0;
char n;
#include<SoftwareSerial.h>
int RX = 2;
int TX = 3;
SoftwareSerial mybt(RX,TX);
int int1 = 11;
int int2 = 10;
int int3 = 9;
int int4 = 8;
int enA = 5;
int enB = 6;
void setup() {
pinMode(int1, OUTPUT); 
pinMode(int2, OUTPUT); 
pinMode(int3, OUTPUT); 
pinMode(int4, OUTPUT); 
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
Serial.begin(9600);
mybt.begin(9600);
}

void loop() {
if(mybt.available()>0)
{
m= mybt.read();
Serial.println(m);
if(m=='F')

{
digitalWrite(int1, HIGH);
digitalWrite(int2, LOW);
digitalWrite(int3, HIGH);
digitalWrite(int4, LOW);
analogWrite(enA, 255);
analogWrite(enB, 255);
}

else if(m=='B')

{
digitalWrite(int1, LOW);
digitalWrite(int2, HIGH);
digitalWrite(int3, LOW);
digitalWrite(int4, HIGH);
analogWrite(enA, 255);
analogWrite(enB, 255);
}

else if(m=='R')

{
digitalWrite(int1, LOW);
digitalWrite(int2, HIGH);
digitalWrite(int3, HIGH);
digitalWrite(int4, LOW);
analogWrite(enA, 255);
analogWrite(enB, 255);
}
else if(m=='L')

{
digitalWrite(int1, HIGH);
digitalWrite(int2, LOW);
digitalWrite(int3, LOW);
digitalWrite(int4, HIGH);
analogWrite(enA, 255);
analogWrite(enB, 255);
}

else if(m=='N')

{
digitalWrite(int1, LOW);
digitalWrite(int2, LOW);
digitalWrite(int3, LOW);
digitalWrite(int4, LOW);
analogWrite(enA, 0);
analogWrite(enB, 0);
}

//else
//{
//  digitalWrite(int1, LOW);
//  digitalWrite(int2, LOW);
//  digitalWrite(int3, LOW);
//  digitalWrite(int4, LOW);
//  analogWrite(enA, 0);
//  analogWrite(enB, 0);
//}

} }
