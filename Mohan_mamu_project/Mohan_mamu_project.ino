#include <SoftwareSerial.h>
SoftwareSerial BlueTooth(0, 1);    // (TXD, RXD) of HC-06
char BT_input;                    // to store input character received via BT.
int motorPin1 = 8;                // pin 2 on L293D IC
int motorPin2 = 9;                // pin 7 on L293D IC
int motorPin3 = 10;               // pin 15 on L293D IC
int motorPin4 = 11;               // pin 10 on L293D IC

void setup()  
{
  BlueTooth.begin(9600);  
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop() 
{
  if (BlueTooth.available())
  {
   BT_input=BlueTooth.read();
   Serial.println(BT_input);
    if (BT_input=='1')
    {
   
      Serial.println("forward");
    }
    else if (BT_input=='2')
    {
  
      Serial.println("backward");
    }
    else if (BT_input=='3')
    {
 
      Serial.println("right");
    }
   else if (BT_input=='4')
    {
 
      Serial.println("left");
    }
    else if (BT_input=='5')
    {
      Serial.println("Stop");
    }
  }
 else{
  
  
  }
}
