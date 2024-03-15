#include<Servo.h>
int ldr1=A0;
int servo=9;
int ldr2=A1;
Servo myservo; 
int pos=0;
void setup() {
Serial.begin(9600);
pinMode(ldr1,INPUT);
pinMode(ldr2,INPUT);
myservo.attach(servo);

}

void loop() {
int   a=analogRead(ldr1);
  int b=analogRead(ldr2);
Serial.print("first ldr value is :");
Serial.println(a);
Serial.print("secound  ldr value is :");
Serial.println(b);
if (a<=40){
  Serial.println("moving upwards ");
  for (pos = 0; pos <= 180; pos += 1) 
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
else if (b<=40){

for (pos = 0; pos <= 180; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
else {
  Serial.println("solar pannel in correct place");
  }
}
