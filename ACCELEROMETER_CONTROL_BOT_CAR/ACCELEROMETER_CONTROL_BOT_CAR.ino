#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int m11=16;
int m12=5;
int m21=4;
int m22=0;
//int s1=2;
//int s2=14;
//int s3=12;
//int s4=13;
//int s5=15;
int forward(){
  
  Serial.println("forward");
     digitalWrite(m11, HIGH);
     digitalWrite(m12, LOW);
      digitalWrite(m21, LOW);
      digitalWrite(m22, HIGH);

  }
int backward(){
   Serial.println("back");
      digitalWrite(m11, LOW);
      digitalWrite(m12, HIGH);
      digitalWrite(m21, HIGH);
      digitalWrite(m22, LOW);
  }

  int right(){
        Serial.println("right");
      digitalWrite(m11, LOW);
      digitalWrite(m12, HIGH);
      digitalWrite(m21, LOW);
      digitalWrite(m22, HIGH);

  }

int left(){

  Serial.println("left");
      digitalWrite(m11, HIGH);
      digitalWrite(m12, LOW);
      digitalWrite(m21, HIGH);
      digitalWrite(m22, LOW);
       }
  int stoppin(){
          Serial.println("stop");
      digitalWrite(m11, HIGH);
      digitalWrite(m12, HIGH);
      digitalWrite(m21, HIGH);
      digitalWrite(m22, HIGH);
    }
 
char auth[] = "A-N_wDpQZOhrcK9v61mH98xC9ANfdoQO";
int l,a;
char ssid[] = "hii";
char pass[] = "";

BLYNK_WRITE(V0) { 
   
  int  x=param[0].asInt();
  int  y = param[1].asInt();
  int  z = param[2].asInt();
// Serial.print("x= ");
// Serial.println(x);
// Serial.print("y= ");
// Serial.println(y);
// Serial.print("z= ");
// Serial.println(z); 
  if ( y<-2){
      forward(); 
}
      
   else  if (x>4){
      
      left();
}    
    else if (x<-2){
   right();
    }

   else if  (y>3){
      backward();
    }

    else if (y=0,x=0,z=9){
        stoppin();
}
 


}
void setup() {
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
   pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
   //pinMode(enb1, OUTPUT);
//    //pinMode(enb2, OUTPUT);
//  pinMode(s1,INPUT);
//  pinMode(s2,INPUT);
//  pinMode(s3,INPUT);
//  pinMode(s4,INPUT);
//  pinMode(s5,INPUT);

}

void loop() {
  
 
        //Serial.println(x);    
       Blynk.run();
}
//     //Serial.println(a);
//     int a=digitalRead(s1);
//     int b=digitalRead(s2);
//     int c=digitalRead(s3);
//     int d=digitalRead(s4);
//     int e=digitalRead(s5); 
      
//if (s1=HIGH){
//
// forward();
//  }
//if (s2=HIGH){
//
// left();
//  } 
//
//if (s3=HIGH){
//
// right();
//  }
//
//if (s4=HIGH){
//
//backward();
//  
//}
//if (s5=HIGH){
//
// stoppin();
//  }
//
//}
