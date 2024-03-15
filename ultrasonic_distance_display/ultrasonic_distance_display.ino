#include <Servo.h>
#include <UltrasonicSensor.h>
#include<LiquidCrystal.h>
int pos=0;
int servopin=4;
int servodelay=1000;
int trigpin= 1;
int echopin=2;
float pingtime;
float speedofsound=767.269;
float targetdistance;
int intr1=5;
int intr2=6;
int intr3=7;
int intr4=8;
int enable=9;
int enable1=10;
Servo Mypointer;
LiquidCrystal Lcd(10,9,8,7,6,5);

void setup() {
  Serial.begin(96000);
  Lcd.begin(16,2);
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  Lcd.setCursor(0,0);
  Mypointer.attach(pos);
  
  }
  
void loop() {
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(1000); 
  digitalWrite(trigpin,HIGH);

 pingtime= pulseIn(echopin,HIGH);
 pingtime=pingtime/1000000;
 pingtime=pingtime/3600;
 targetdistance=speedofsound*pingtime;
 targetdistance=targetdistance/2;
 Serial.print("distance of the object ");
 Serial.print(pingtime);
  Lcd.print(targetdistance);
//  if (targetdistance==3){
//    Mypointer.write(servopin);
//    delay(servodelay);
//    digitalWrite(intr1,HIGH);
//    digitalWrite(intr2,LOW);
//    digitalWrite(intr3,HIGH);
//    digitalWrite(intr4,LOW);
//    digitalWrite(enable,HIGH);
//    digitalWrite(enable,HIGH);
//    
//    
//    }

float distance=targetdistance;
if (distance<=3.0){
  Serial.println("now you are too near");
  digitalWrite(intr1,HIGH);
    digitalWrite(intr2,LOW);
    digitalWrite(intr3,HIGH);
    digitalWrite(intr4,LOW);
    digitalWrite(enable,HIGH);
    digitalWrite(enable1,HIGH);
    
  }
 }
