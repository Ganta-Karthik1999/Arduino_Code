#include<SoftwareSerial.h>  
int m11 = 7;
int m12 = 8;
int m21 = 11;
int m22 = 12;
int a;
int enb=5;
int enb1=6;

SoftwareSerial BT(1, 0);
//String readData; 
void setup() {

  BT.begin(9600);
  Serial.begin(9600);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(enb1,OUTPUT);
  // put your setup code here, to run once:
}

void loop() {
  //while (BT.available() > 0)
  //{
   // delay(10);
  //  char a = BT.read();
    //readData +=a;1
    

    if (Serial.available()>0) {}

    int a=Serial.read(); 
    if (a == '1') {
      Serial.println("you are moving forward");
      digitalWrite(m11, HIGH);
     digitalWrite(m12, LOW);
      digitalWrite(m21, LOW);
      digitalWrite(m22, HIGH);
      digitalWrite(enb,HIGH);
      digitalWrite(enb1,HIGH);
      
      }
    else if (a == '2') {
      Serial.println("you are moving backward");
      digitalWrite(m11, LOW);
      digitalWrite(m12, HIGH);
      digitalWrite(m21, HIGH);
      digitalWrite(m22, HIGH);
       digitalWrite(enb,HIGH);
      digitalWrite(enb1,HIGH);
    }

    else if (a == '3') {
      Serial.println("you are moving left");
      digitalWrite(m11, LOW);
      digitalWrite(m12, LOW);
      digitalWrite(m21, LOW);
      digitalWrite(m22, HIGH);
       digitalWrite(enb,HIGH);
      digitalWrite(enb1,HIGH);
    }

    else if (a == '4') {
      Serial.println("you are moving right ");
      digitalWrite(m11, LOW);
      digitalWrite(m12, HIGH);
      digitalWrite(m21, LOW);
      digitalWrite(m22, HIGH);
       digitalWrite(enb,HIGH);
      digitalWrite(enb1,HIGH);
    }

    else if (a == '5') {
      Serial.println("you are now stopped");
      digitalWrite(m11, HIGH);
      digitalWrite(m12, HIGH);
      digitalWrite(m21, HIGH);
      digitalWrite(m22, HIGH);
       digitalWrite(enb,HIGH);
      digitalWrite(enb1,HIGH);
    }
  }
//}// put your main code here, to run repeatedly:
