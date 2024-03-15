#include<SoftwareSerial.h>
//int trigPin=13; //Sensor Trip pin connected to Arduino pin 13
//int echoPin=11;  //Sensor Echo pin connected to Arduino pin 11
float speedOfSound=776.5; //Speed of sound in miles per hour when temp is 77 degrees.
float pingTime;  //time for ping to travel from sensor to target and return
float targetDistance; //Distance to Target in inchesint  IN1=12;
int  IN1=12;
int  IN2=11;
int  IN3=10;
int  IN4=9;
int trigPin=7 ;
int echoPin=6;

SoftwareSerial mySerial(0, 1); // RX, TX

String data;
int btVal;

void setup() 
{  
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}

void loop()
{

 
  digitalWrite(trigPin, LOW); //Set trigger pin low
  delayMicroseconds(2000); //Let signal settle
  digitalWrite(trigPin, HIGH); //Set trigPin high
  delayMicroseconds(15); //Delay in high state
  digitalWrite(trigPin, LOW); //ping has now been sent
  delayMicroseconds(10); //Delay in low state
  
  pingTime = pulseIn(echoPin, HIGH);  //pingTime is presented in microceconds
  pingTime=pingTime/1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
  pingTime=pingTime/3600; //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
  targetDistance= speedOfSound * pingTime;  //This will be in miles, since speed of sound was miles per hour
  targetDistance=targetDistance/2; //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
  targetDistance= targetDistance*63360;    //Convert miles to inches by multipling by 63360 (inches per mile)
////  
//  Serial.print("The Distance to Target is: ");
//  Serial.print(targetDistance);
//Serial.println(" inches");
 while (Serial.available()>0)
    { 
 
      
char  data = Serial.read();
      //Serial.print(str);  
      Serial.println(data);           
  
  if (targetDistance>4.0){
    
  if (data=='C'){
  Serial.println("FORWARD");
   forward();
  }
  
else if (data=='D'){
  reverse();
  }

else if (data=='B'){
  left();
  }
else if (data=='A'){
  right();
  }
else if(data=='E') {
 
  stoprobot();
  }
    } 
  else if(targetDistance<=4.0){
  
     stoprobot();
  
    }
  else{
    Serial.println("th value is 4.0");
    }
}
  }

void forward()
{
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void reverse()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stoprobot()
{
  Serial.println("robotstoped");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}    
