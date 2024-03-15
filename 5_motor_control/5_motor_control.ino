
#include<SoftwareSerial.h>

SoftwareSerial BlueTooth(0,1);  
int BT_input;                  
int motorPin1=8;                
int motorPin2=9;                
int motorPin3=10;                
int motorPin4=11; 
int motorPin5=4;  
int motorPin6=5; 
int motorPin7=6; 
int motorPin8=7; 
int motorPin9=2; 
int motorPin10=3; 
              
void setup()
{
  BlueTooth.begin(9600);
  Serial.begin(9600);
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
   pinMode(motorPin3,OUTPUT);
  pinMode(motorPin4,OUTPUT);
  pinMode(motorPin5,OUTPUT);
  pinMode(motorPin6,OUTPUT);
   pinMode(motorPin7,OUTPUT);
  pinMode(motorPin8,OUTPUT);
   pinMode(motorPin9,OUTPUT);
    pinMode(motorPin10,OUTPUT);
}
void loop()
 {
  if(BlueTooth.available()>0)
    {
    BT_input=BlueTooth.read();
    Serial.println(BT_input);
          
   if(BT_input==53)
   {
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin3,LOW);
    digitalWrite(motorPin4,LOW);
    digitalWrite(motorPin5,LOW);
    digitalWrite(motorPin6,LOW);
    digitalWrite(motorPin7,LOW);
    digitalWrite(motorPin8,LOW);
    digitalWrite(motorPin9,LOW);
    digitalWrite(motorPin10,LOW);
    Serial.println("stop");
   }
 
  else if(BT_input==52)
  {
    digitalWrite(motorPin1,HIGH);
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin3,LOW);
    digitalWrite(motorPin4,HIGH);
    Serial.println("backward");
  }

  else if(BT_input==49)
  {
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,HIGH);
    digitalWrite(motorPin3,HIGH);
    digitalWrite(motorPin4,LOW);
    Serial.println("forward");
  }
  
  else if(BT_input==50)
  {
    digitalWrite(motorPin1,HIGH);
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin3,HIGH);
    digitalWrite(motorPin4,LOW);
    Serial.println("left");
  }
  
  else if(BT_input==51)
  {
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,HIGH);
    digitalWrite(motorPin3,LOW);
    digitalWrite(motorPin4,HIGH);
    Serial.println("right");
  }
  else if(BT_input==54)
  {
    digitalWrite(motorPin5,LOW);
    digitalWrite(motorPin6,HIGH);
   // digitalWrite(motorPin3,LOW);
    //digitalWrite(motorPin4,HIGH);
    Serial.println("clock wise");
  }
  else if(BT_input==55)
  {
   // digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin5,HIGH);
    digitalWrite(motorPin6,LOW);
   // digitalWrite(motorPin4,HIGH);
    Serial.println("anticlock wise");
  }
   else if(BT_input==56)
  {
    digitalWrite(motorPin7,LOW);
    digitalWrite(motorPin8,HIGH);
   // digitalWrite(motorPin3,LOW);
    //digitalWrite(motorPin4,HIGH);
    Serial.println("hold");
  }
  else if(BT_input==57)
  {
   // digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin7,HIGH);
    digitalWrite(motorPin8,LOW);
   // digitalWrite(motorPin4,HIGH);
    Serial.println("leave");
  }
  else if(BT_input==48)
  {
    digitalWrite(motorPin9,LOW);
    digitalWrite(motorPin10,HIGH);
    //digitalWrite(motorPin8,LOW);
   // digitalWrite(motorPin4,HIGH);
    Serial.println("up");
  }
  else if(BT_input==61)//==
  {
   // digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin9,HIGH);
    digitalWrite(motorPin10,LOW);
   // digitalWrite(motorPin4,HIGH);
    Serial.println("down");
  }
 }
}
