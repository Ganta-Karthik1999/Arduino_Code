#include <SoftwareSerial.h>
SoftwareSerial mySerial (D1,D2);
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
int trigP=2;
int echoP=0;
//int pingTravelTime;
char auth[] = "Tqvz7rzmh2NaapQqrfEiYoW581mVvA2S";
char ssid[] = "ACT107389225313";
char pass[] = "82267762";
char buf[]={};
int len;
void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  mySerial.begin(9600);
pinMode(trigP,OUTPUT);
pinMode(echoP,INPUT);
pinMode(D0,OUTPUT);
  
}



void loop() {
Blynk.run();
digitalWrite(trigP, LOW);   // Makes trigPin low
delayMicroseconds(2);       // 2 micro second delay 

digitalWrite(trigP, HIGH);  // tigPin high
delayMicroseconds(10);      // trigPin high for 10 micro seconds
digitalWrite(trigP, LOW);   // trigPin low

int duration = pulseIn(echoP, HIGH);   //Read echo pin, time in microseconds
int distance= duration*0.034/2;        //Calculating actual/real distance

//Serial.print("Distance = ");        //Output distance on arduino serial monitor 
//Serial.println(distance);
if (distance<10){
//  Serial.println("ya");
  digitalWrite(D0,HIGH);
  
  }
  else{
  digitalWrite(D0,LOW);
    
    
    }
//digitalWrite(D0,HIGH);
String msg=mySerial.readStringUntil('\r');
Serial.println(msg);
//  int str_len=msg.length()+1;
//  char char_array[str_len];
//  msg.toCharArray(char_array,str_len);
//  Serial.print(char_array[0]);
//  Serial.print(char_array[1]);
//int a=Serial.read();
//  Serial.println(a);
Blynk.virtualWrite(V6,msg);
  
}
