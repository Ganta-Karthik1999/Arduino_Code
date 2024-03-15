#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "DFYk4RfbKlhl10CElBlrJQ3GSUmeG5KT";
char ssid[] = "ACT107389225313";
char pass[] = "82267762";
int a;

 
Servo myservo;  // create servo object to control a servo
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

//int potpin = A0;
//int potpin1= A1;// analog pin used to connect the potentiometer
//int potpin2= A2;
//int potpin3= A3;

void setup() 
{
Serial.begin(115200);
Blynk.begin(auth, ssid, pass);
myservo.attach(D1);
myservo1.attach(D2);
myservo2.attach(D3);
myservo3.attach(D4);
myservo4.attach(D5);
myservo5.attach(D6);


}
BLYNK_WRITE(V0) // V5 is the number of Virtual Pin  
{
  int pinValue = param.asInt();
  int val = pinValue;
  val= map(val, 0, 1023,40,110);  
  myservo.write(val);
  Serial.print("val: ");
  Serial.println(val);


  Serial.println(pinValue);
}

BLYNK_WRITE(V1) // V5 is the number of Virtual Pin  
{
  int pinValue1 = param.asInt();
   int  val1 =pinValue1;
  val1= map(val1, 0, 1023,40,110);
  myservo1.write(val1);
  Serial.print("val1: ");  
  Serial.println(val1);
  Serial.println(pinValue1);
}
BLYNK_WRITE(V2) // V5 is the number of Virtual Pin  
{
  int pinValue2 = param.asInt();
  int val2 = pinValue2;
val2= map(val2, 0, 1023,80,120 );
myservo2.write(val2);
Serial.print("val2: ");
  Serial.println(pinValue2);
}
BLYNK_WRITE(V3) // V5 is the number of Virtual Pin  
{
  int pinValue3 = param.asInt();
  int val3 = pinValue3;
val3= map(val3, 0, 1023,20,160);
myservo3.write(val3);
Serial.print("val3: ");
  Serial.println(pinValue3);
}
BLYNK_WRITE(V4) // V5 is the number of Virtual Pin  
{
  int pinValue4 = param.asInt();
  int val4 = pinValue4;
val4= map(val4, 0, 1023,20,160);
myservo4.write(val4);
Serial.print("val4: ");
  Serial.println(pinValue4);
}
BLYNK_WRITE(V5) // V5 is the number of Virtual Pin  
{
  int pinValue5 = param.asInt();
  if(pinValue5>0){
myservo5.write(180);
  }
  else{
    myservo5.write(120);
 
    }
}



void loop()
{

Blynk.run();
//myservo5.write(180);
//a =analogRead(16);
//Serial.print("value of a : ");
//Serial.println(a);

}
