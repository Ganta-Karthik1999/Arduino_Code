//#include <UltrasonicSensor.h>
//int m11 = 8;
//int m12 = 9;
//int m21 = 10;
//int m22 = 11;
//int enb1=3;//SD3
//int enb2=2;
int trigPin=8;
int echoPin=9;  //Sensor Echo pin connected to Arduino pin 11
//int=13; //Sensor Trip pin connected to Arduino pin 13
//int servoControlPin=6; //Servo control line is connected to pin 6
float pingTime;  //time for ping to travel from sensor to target and return
float targetDistance; //Distance to Target in inches
float speedOfSound=776.5; //Speed of sound in miles per hour when temp is 77 degrees.
//float servoAngle; //Variable for the value we want to set servo to.


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//  pinMode(servoControlPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
//  pinMode(m11, OUTPUT);
//  pinMode(m12, OUTPUT);
//  pinMode(m21, OUTPUT);
//  pinMode(m22, OUTPUT);
//  pinMode(enb1, OUTPUT);
//  pinMode(enb2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite(13,HIGH);
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
  
  //Serial.print("The Distance to Target is: ");
  Serial.println(targetDistance);
  //Serial.println(" inches");
//  if (targetDistance<=6){
//    Serial.println("hi");
//    digitalWrite(m11, HIGH);
//      digitalWrite(m12, LOW);
//      digitalWrite(m21, LOW);
//      digitalWrite(m22, LOW);
//      digitalWrite (enb1, HIGH);
//       digitalWrite (enb2, HIGH);
//    }
//  else{
//       digitalWrite(m11, HIGH);
//     digitalWrite(m12, HIGH);
//      digitalWrite(m21, HIGH);
//      digitalWrite(m22, HIGH);
//      digitalWrite(enb1, HIGH);
//       digitalWrite(enb2, HIGH);
//    }
}
