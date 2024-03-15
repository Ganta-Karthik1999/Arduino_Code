void setup() {
 pinMode(A0,INPUT);
 pinMode(D0,OUTPUT);
 Serial.begin(115200);
digitalWrite(D0,LOW);
}

void loop() {
 int ldr =analogRead(A0);
 Serial.println(ldr);
 if(ldr<=900){
  digitalWrite(D0,HIGH);
 }
 else{
  digitalWrite(D0,LOW);
  } 

}
