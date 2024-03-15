/* Get tilt angles on X and Y, and rotation angle on Z
 * Angles are given in degrees
 * 
 * License: MIT
 */

#include "Wire.h"
#include <MPU6050_light.h>
int node1=11;
int node2=9;
int mot1=8;
int mot2=6;
MPU6050 mpu(Wire);
unsigned long timer = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.begin();
  Serial.println(F("Calculating gyro offset, do not move MPU6050"));
  delay(1000);
  mpu.calcGyroOffsets();
Serial.println("Done!\n");
pinMode(node1,INPUT);
pinMode(node2,INPUT);
pinMode(mot1,OUTPUT);
pinMode(mot2,OUTPUT);
digitalWrite(mot1,LOW);
digitalWrite(mot2,LOW);
}

void loop() {
 
  mpu.update();

digitalWrite(mot1,LOW);
digitalWrite(mot2,LOW);
int a=digitalRead(node1); 
int b=digitalRead(node2);
if (a==HIGH or a==1){
   digitalWrite(mot1,HIGH);
  digitalWrite(mot2,LOW);
}
else  if (b==HIGH or b==1){
   digitalWrite(mot1,LOW);
  digitalWrite(mot2,HIGH);
  
  }
else{
  digitalWrite(mot1,LOW);
  digitalWrite(mot2,LOW);    
  }
  
   
  if((millis()-timer)>10){
 
float angle =mpu.getAngleZ();
//float roll=constrain(angle,-360,360);
//value1=map(roll,-360,360,0,0);
////float value1=value(angle);
//Serial.println(value1);

float temp=angle/360;
int a=(int)temp;
int b=a*360;
int angle1=angle-b;
Serial.println(angle1); 
//Serial.println (angle);
  timer = millis();
angle=0;  
  }

}
//
//float value(float a){
//  if(a>360 ){
//  float angle1=0;
//  return angle1;  
// }
// else{
//  return a;
//  }
//  
//  }
