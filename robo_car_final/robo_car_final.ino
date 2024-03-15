#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "xfqV1U7zakVmkYEgM1kVuP0XRtxKdhmB";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Why for you";// put your wifi  name here 
char pass[] = "1234567890";// please put your wifi password here
int a,b,c,d,e;

int m11 = 16;
int m12 = 5;
int m21 = 4;
int m22 = 0;
int ena = 13;
int enb = 15;
void setup() {
 // SoftwareSerial bt(1, 0);
  //bt.begin(9600);
   Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
 pinMode(m22, OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  // put your setup code here, to run once:
}

void loop() {
//  if(Serial.available()>0) 
  //{
  
  //  int a= Serial.read();
      Blynk.run();
  a=digitalRead(2);
  b=digitalRead(14);
  c=digitalRead(12);
  d=digitalRead(13);
  e=digitalRead(15);

    if (a == HIGH) {
      
      digitalWrite(m11, HIGH);
      digitalWrite(m12, LOW);
      digitalWrite(m21, LOW);
      digitalWrite(m22, HIGH);
     analogWrite(ena,HIGH);
      analogWrite(enb,HIGH);
    }
    else if (b == HIGH) {
      digitalWrite(m11, LOW);
      digitalWrite(m12, HIGH);
      digitalWrite(m21, HIGH);
      digitalWrite(m22, HIGH);
      analogWrite(ena,HIGH);
      analogWrite(enb,HIGH);
    }

    else if (c == HIGH) {
      digitalWrite(m11, LOW);
      digitalWrite(m12, LOW);
      digitalWrite(m21, LOW);
      digitalWrite(m22, HIGH);
      analogWrite(ena,HIGH);
      analogWrite(enb,HIGH);
    }

    else if (d == HIGH) {

      digitalWrite(m11, LOW);
      digitalWrite(m12, HIGH);
      digitalWrite(m21, HIGH);
      digitalWrite(m22, LOW);
      analogWrite(ena,HIGH);
      analogWrite(enb,HIGH);
    }

    else  { 
      digitalWrite(m11, HIGH);
      digitalWrite(m12, HIGH);
      digitalWrite(m21, HIGH);
      digitalWrite(m22, HIGH);
       analogWrite(ena,HIGH);
      analogWrite(enb,HIGH);
    }
    
  }
//}// put your main code here, to run repeatedly:
