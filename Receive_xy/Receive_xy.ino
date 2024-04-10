// Code mạch nhận
char p =0;
char m=0;
char n;
char last_m = 0;
int d=0;
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
//int sp;
//int trig =13, echo = 12;


//float getdis()
//{
//    digitalWrite(trig,LOW);   // tắt chân trig
//    delayMicroseconds(2);
//    digitalWrite(trig,HIGH);   // phát xung từ chân trig
//    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
//    digitalWrite(trig,HIGH);   // tắt chân trig
//    
//    /* Tính toán thời gian */
//    // Đo độ rộng xung HIGH ở chân echo. 
//    float duration = pulseIn(echo,HIGH);  
//    // Tính khoảng cách đến vật.
//     return duration*0.029/2;
//}
void stop()
{
 digitalWrite(int1, LOW);
digitalWrite(int2, LOW);
digitalWrite(int3, LOW);
digitalWrite(int4, LOW);
analogWrite(enA, 0);
analogWrite(enB, 0);
}
void go(int sp)
{
  digitalWrite(int1, HIGH);
  digitalWrite(int2, LOW);
  digitalWrite(int3, HIGH);
  digitalWrite(int4, LOW);
  analogWrite(enA, sp);
  analogWrite(enB, sp);
}
void back(int sp)
{
  digitalWrite(int1, LOW);
  digitalWrite(int2, HIGH);
  digitalWrite(int3, LOW);
  digitalWrite(int4, HIGH);
  analogWrite(enA, sp);
  analogWrite(enB, sp);
}
void right(int sp)
{
  digitalWrite(int1, HIGH);
  digitalWrite(int2, LOW);
  digitalWrite(int3, LOW);
  digitalWrite(int4, HIGH);
  analogWrite(enA, sp);
  analogWrite(enB, sp);
}
void left(int sp)
{
  digitalWrite(int1, LOW);
  digitalWrite(int2, HIGH);
  digitalWrite(int3, HIGH);
  digitalWrite(int4, LOW);
  analogWrite(enA, sp);
  analogWrite(enB, sp);
}


void setup() {
pinMode(int1, OUTPUT); 
pinMode(int2, OUTPUT); 
pinMode(int3, OUTPUT); 
pinMode(int4, OUTPUT); 
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
//pinMode(trig, OUTPUT);
//pinMode(echo, INPUT);
Serial.begin(9600);
mybt.begin(9600);
}
int chuyen(char a)
{
  if(a=='1') return 1;
  if(a=='2') return 2;
  if(a=='3') return 3;
  if(a=='4') return 4;
  if(a=='5') return 5;
  if(a=='6') return 6;
  if(a=='7') return 7;
  if(a=='8') return 8;
  if(a=='9') return 9;
}

void loop() {
if(mybt.available()>0)
{
char i = mybt.read();
if(i=='F' || i=='B' || i=='L' || i =='R' || i == 'N')
{
  m = i; 
  last_m = m;
} else
{
  m = last_m;
  d++;
  if(d == 2){
    m='N';
    d=0;
  }
}
Serial.print("m= ");Serial.println(m);
p= mybt.read();
if(p>='1' && p<='9')
n= p;
int sp = chuyen(n);
Serial.print("n= ");Serial.println(n);
Serial.print("sp= ");Serial.println(sp);
sp = map( sp , 1 , 9 , 180 , 230 );
Serial.print("sp= ");Serial.println(sp);

if(m=='F')
{go(sp);}
else if(m=='B')//slow 175
{back(sp);}
else if(m=='L')//fast 220
{left(sp);}
else if(m=='R')//fast 220
{right(sp);}
else if(m=='N')//stop
{stop();}
else//stop without signal
{stop();}

} 
}
