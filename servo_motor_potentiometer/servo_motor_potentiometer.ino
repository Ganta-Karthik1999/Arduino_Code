#include<Servo.h>
int pos=0;
int servopin=1;
int potinput=2;
 int servodelay=1000;
Servo mypointer;
void setup() {
  Serial.begin(9600);
  mypointer.attach(servopin);
}

void loop() {
  for(pos=0;pos<=100;pos++){
    mypointer.write(pos);
    delay(servodelay);
    }
 

}
