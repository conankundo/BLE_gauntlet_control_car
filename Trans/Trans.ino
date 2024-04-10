// Code mạch truyền
int m=0,n=0;
void setup() {
pinMode(A0, INPUT);
pinMode(A1, INPUT);
Serial.begin(9600);
}
void loop() {
m = analogRead(A0);  //y
n = analogRead(A1);  //x
if(n>=375)
{
Serial.write("F");
Serial.println("F");
}
else if(n<=320) 
{ 
Serial.write("B"); 
Serial.println("B");
} else if(m>=375)
{
Serial.write("R");
Serial.println("R");
}
else if(m<=315)
{
Serial.write("L");
Serial.println("L");
}
else
{
Serial.write("N");
Serial.println("N");
}
}
