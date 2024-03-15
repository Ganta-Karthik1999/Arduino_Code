
int x,y,z;
void setup() {
  Serial.begin(9600);
  Serial.println("RGB COLIOURS");
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  x=y=z=0;
}

void loop() {
  x= Serial.parseInt();
  y=Serial.parseInt();
  z=Serial.parseInt();
  if (Serial.available()>0){
    analogWrite(3,255-x); 
    
    }
else if(Serial.available()){
  analogWrite(5,255-y);
  }
  else if(Serial.available()){
  analogWrite(6,255-y);
  }
 
}
