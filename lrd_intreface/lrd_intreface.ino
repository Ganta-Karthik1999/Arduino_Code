int a;
void setup() {
Serial.begin(115200);
pinMode(D1,INPUT);
pinMode(D0,OUTPUT);
digitalWrite(D0,LOW);
}

void loop() {
  
 a=digitalRead(D1);
Serial.println(a);

}
