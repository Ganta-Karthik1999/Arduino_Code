 
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo1;
Servo myservo2;
Servo myservo3;

int potpin = A0;
int potpin1= A1;// analog pin used to connect the potentiometer
int potpin2= A2;
int potpin3= A3;

void setup() {
  // Servo knob demo by Robojax.com
  Serial.begin(9600); 
  myservo.attach(9);
  myservo1.attach(10);
  myservo2.attach(11);
  myservo3.attach(6);
  
}

void loop() {


int val = analogRead(potpin);
val= map(val, 0, 1023,40,110);
myservo.write(val);
Serial.print("val: ");
Serial.println(val);


int  val1 = analogRead(potpin1);
val1= map(val1, 0, 1023,40,110);
myservo1.write(val1);
Serial.print("val1: ");  
Serial.println(val1);

int val2 = analogRead(potpin2);
val2= map(val2, 0, 1023,80,120 );
myservo2.write(val2);
Serial.print("val2: ");
//Serial.println(val2);


int val3 = analogRead(potpin3);
val3= map(val3, 0, 1023,130,175 );
myservo3.write(val3);
Serial.print("val3: ");
//Serial.println(val3);


delay(200);
 

}
