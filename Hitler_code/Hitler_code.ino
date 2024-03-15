#include<SoftwareSerial.h>

SoftwareSerial BlueTooth(0,1);  
int BT_input;                  
int motorPin1=8;                
int motorPin2=9;                
int motorPin3=10;                
int motorPin4=11; 
           
void setup()
{
  BlueTooth.begin(9600);
  Serial.begin(9600);
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  pinMode(motorPin3,OUTPUT);
  pinMode(motorPin4,OUTPUT);

}
void loop()
 {
//  if(BlueTooth.available()>0)
//    {
//    BT_input=BlueTooth.read();
//    Serial.println(BT_input);
//    
//  
 
 int a=Serial.read();        
   if(a==53)
   {
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin3,LOW);
    digitalWrite(motorPin4,LOW);
    Serial.println("stop");
   }
 
  else if(a==52)
  {
    digitalWrite(motorPin1,HIGH);
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin3,LOW);
    digitalWrite(motorPin4,HIGH);
    Serial.println("backward");
  }

  else if(a==49)
  {
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,HIGH);
    digitalWrite(motorPin3,HIGH);
    digitalWrite(motorPin4,LOW);
    Serial.println("forward");
  }
  
  else if(a==50)
  {
    digitalWrite(motorPin1,HIGH);
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin3,HIGH);
    digitalWrite(motorPin4,LOW);
    Serial.println("left");
  }
  
  else if(a==51)
  {
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,HIGH);
    digitalWrite(motorPin3,LOW);
    digitalWrite(motorPin4,HIGH);
    Serial.println("right");
  }
 // }
}
