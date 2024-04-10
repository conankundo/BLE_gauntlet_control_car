// Code mạch truyền
// Các chữ cái mã hóa tiến F, W; lùi B, X
// sang phải R, D; sang trái A, L
int y=0,x=0;
void setup() {
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
Serial.begin(9600);
}
void loop() {
y = analogRead(A0);  //y
x = analogRead(A1);  //x


if(x>=375)
{
Serial.write("X");  //X-F
Serial.println("X");
}
else if(x>=345&&x<375)
{
Serial.write("B");
Serial.println("B");//B_W
}
else if(x<=320&&x>300) 
{ 
Serial.write("W"); //W-B
Serial.println("W");
}
else if(x<=300) 
{ 
Serial.write("F"); //F_X
Serial.println("F");
}
else if(y>=375)
{
Serial.write("R");
Serial.println("R");
}
else if(y>=350&&y<375)
{
Serial.write("D");
Serial.println("D");
}
else if(y>290&&y<310)
{
Serial.write("A");
Serial.println("A");
}
else if(y<290)
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
