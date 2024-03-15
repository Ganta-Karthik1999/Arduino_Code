#include <UltrasonicSensor.h>
int trigpin= 13;
int echopin=11 ;
float pingtime;
float speedofsound=767.269;
float targetdistance;
int intr1=4;
int intr2=0;
int intr3=2;
int intr4=14;
void setup() {
  Serial.begin(9600);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
pinMode(intr1,OUTPUT);
pinMode(intr2,OUTPUT);
pinMode(intr3,OUTPUT);
pinMode(intr4,OUTPUT);
  }

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(15); 
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10); 
 pingtime= pulseIn(echopin,HIGH);
 pingtime=pingtime/1000000;
 pingtime=pingtime/3600; 
 targetdistance=speedofsound*pingtime;
 targetdistance=targetdistance/2;
 targetdistance=targetdistance*63350;
 Serial.println(targetdistance);
 
if (targetdistance<=3.0){
    Serial.println("now you are too near");
    digitalWrite(intr1,HIGH);
    digitalWrite(intr2,HIGH);
    digitalWrite(intr3,HIGH);
    digitalWrite(intr4,HIGH);
    
  }

}
