#include <SoftwareSerial.h>
SoftwareSerial BlueTooth(0, 1);    // (TXD, RXD) of HC-06
char BT_input;          
#define MotorDirection 8
#define MotorSpeed 9
#define MotorDirection1 7
#define MotorSpeed1 6


void setup() {
  BlueTooth.begin(9600);  
  Serial.begin(9600);
 pinMode(MotorDirection, OUTPUT);
  pinMode(MotorSpeed, OUTPUT);
pinMode(MotorDirection1, OUTPUT);
  pinMode(MotorSpeed1, OUTPUT);
}

void loop() {
  if (BlueTooth.available())
  {
   BT_input=BlueTooth.read();
   Serial.println(BT_input);
    if (BT_input=='1')
    {
      Serial.println("forward");
      digitalWrite(MotorDirection, HIGH);                  
      analogWrite(MotorSpeed,255);
      
    }
    else if (BT_input=='2')
    {
  
      Serial.println("backward");
      digitalWrite(MotorDirection, LOW);                  
      analogWrite(MotorSpeed,255);
    }
    else if (BT_input=='3')
    {
      Serial.println("right");
    digitalWrite(MotorDirection1, LOW);                  
      analogWrite(MotorSpeed1,255);
    
    }
   else if (BT_input=='4')
    {
 
      Serial.println("left");
      digitalWrite(MotorDirection1, HIGH);                  
      analogWrite(MotorSpeed1,255);
    }
    else if (BT_input=='5')
    {
      Serial.println("Stop");
    digitalWrite(MotorDirection, LOW);                  
      analogWrite(MotorSpeed,0);
      digitalWrite(MotorDirection1, LOW);                  
      analogWrite(MotorSpeed1,0);
    
    }
  }
 else{
     
  
  }
}
