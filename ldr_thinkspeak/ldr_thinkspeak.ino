

int dip;
void setup() {
  Serial.begin(115200);
  pinMode(A0,INPUT);
  pinMode(D0,OUTPUT);

}

void loop() {
  dip=analogRead(A0);
Serial.println(dip);
delay(1000);
if (dip<10){
  digitalWrite(D0,HIGH);
  }
else{
  digitalWrite(D0,LOW);
  }
}
