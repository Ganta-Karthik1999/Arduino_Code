int led1=2;
int  led2=3;
int  led3=4;
int  led4=5;
int  ir1=A1;
int  ir2=A2;
int   ir3=A3;
int  ir4=A4;
int  ldr=A0;
void setup()
{
 Serial.begin(9600);
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
 pinMode(led4,OUTPUT); 
 pinMode(ldr,INPUT);
 pinMode(ir1,INPUT);
 
}

void loop() 
{
int   a=analogRead(ir1);
int   a1=analogRead(ir2);
int   a2=analogRead(ir3);
int   a3=analogRead(ir4);
 int  b=analogRead(ldr);
//Serial.println(a);
Serial.println(b);
 if(b<900)
 {
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW); 
 }
 else if(b>700)
 {
  if(a<70 or a1<70 or a2<70 or a3<70 )
  {
    Serial.println("loop");
    analogWrite(led1,255);
    digitalWrite(led2,255);
    digitalWrite(led3,255);
    digitalWrite(led4,255);
  }
else
{
    Serial.println("loop2");
    analogWrite(led1,50);
    analogWrite(led2,50);
    analogWrite(led3,50);
    analogWrite(led4,50);
  }
}

}
