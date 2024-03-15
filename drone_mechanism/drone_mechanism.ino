#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "BWAtAYwf-Tp8A3FP1paXEBYktsC-aNPb";
int deciderotation=16;
int motor1=05;
int motor2=0;
int rotate;
int deciderotation2=02;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "hii";
char pass[] = "";

void setup()
{
  // Debug console
Serial.begin(115200);
Blynk.begin(auth, ssid, pass);
pinMode(deciderotation,INPUT);
pinMode(deciderotation2,INPUT);
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
}

void loop()
{
digitalWrite(13,HIGH);
digitalWrite(15,HIGH);
delay(500);
digitalWrite(15,LOW);
digitalWrite(13,LOW);
delay(500);
 rotate=digitalRead(deciderotation);
int rotatereverse=digitalRead(deciderotation2);
Blynk.run();
if (rotate==HIGH)
{
 Serial.println("forward");
  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,LOW);
  
  }
else if(rotatereverse==HIGH) 
{
  Serial.println("BACKWARD");
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,HIGH);
  }

else {
  Serial.println("IDEAL");
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,LOW);
  }
} 
