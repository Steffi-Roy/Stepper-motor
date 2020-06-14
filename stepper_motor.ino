void setup(){
  Serial.begin(9600);
  pinMode(8,OUTPUT);//Green
  pinMode(9,OUTPUT);//Black
  pinMode(10,OUTPUT);//Blue
  pinMode(11,OUTPUT);//Red
  pinMode(A1,INPUT);//vrx
  pinMode(A2,INPUT);//vry no of steps
  pinMode(A3,INPUT);//sw
}

int Qa = 0;
int Qb = 0;
int Da;
int Db;
int n = 4;
int M;
int a;
int b;
int c;
int X;
int Y;
int Xn;
int i;

void loop(){


Serial.print("MANUAL MODE (1) OR AUTOMATIC MODE (2)");
while(Serial.available()==0){
}
int data = Serial.parseInt();
if (Serial.parseInt());

if(data==1){
  Serial.print("MANUAL MODE");
  while(!Serial.available()){
Xn = analogRead(A1); //Speed analogRead(A) returns a 10-bit number (0-1023)
X = map(Xn,0,1023,5,1000);

if (X <= 510)
{ 
  M = 0;
  Db = !Qa ^ M;
  Da = Qb ^ M;
 Serial.print(Qa);
 Serial.println(Qb); //print println
 digitalWrite(8,Qa);
 digitalWrite(9,!Qa);
 digitalWrite(10,Qb);
 digitalWrite(11,!Qb);
 Qa = Da;
 Qb = Db;
 delay(X);
}
else if (X >= 520) 
{
  M = 1;
  Db = !Qa ^ M;
  Da = Qb ^ M;
 Serial.print(Qa);
 Serial.println(Qb); //print println
 digitalWrite(8,Qa);
 digitalWrite(9,!Qa);
 digitalWrite(10,Qb);
 digitalWrite(11,!Qb);
 Qa = Da;
 Qb = Db;
 
delay(1023-X);
}
else
{};

}
}

else if (data == 2){
  Serial.print("AUTO");
  X = analogRead(A1);
  Y = analogRead(A2);
  
Serial.print("CCK (1) OR CK (2)");    //input direction M
while(Serial.available()==0){
}
int M = Serial.parseInt();
if (Serial.parseInt());
  for(i=0; i<Y; i++)
  {
  if(M=1)
  {
  Db = !Qa ^ M;
  Da = Qb ^ M;
 Serial.print(Qa);
 Serial.println(Qb); //print println
 digitalWrite(8,Qa);
 digitalWrite(9,!Qa);
 digitalWrite(10,Qb);
 digitalWrite(11,!Qb);
 Qa = Da;
 Qb = Db;
 delay(X);
  }
  else if (M=2)
  {
  Db = !Qa ^ M;
  Da = Qb ^ M;
 Serial.print(Qa);
 Serial.println(Qb); //print println
 digitalWrite(8,Qa);
 digitalWrite(9,!Qa);
 digitalWrite(10,Qb);
 digitalWrite(11,!Qb);
 Qa = Da;
 Qb = Db;
 delay(1023-X);
}
else
{}
}
}
else{}
}
