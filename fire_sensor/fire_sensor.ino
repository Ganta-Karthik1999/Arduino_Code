int fires=8;
int fires1=7;
int fires2=4;
int relay=2;
int relay1=1;
int relay0=0;
void setup() {
  Serial.begin(9600);
  pinMode(fires,INPUT);
  pinMode(fires1,INPUT);
  pinMode(fires2,INPUT);
}

void loop() {
int a=digitalRead(fires);
int b=digitalRead(fires1);
int c=digitalRead(fires2);
Serial.print("first sensor value: ");
Serial.println(a);
Serial.print("secound sensor value: ");
Serial.println(b);
Serial.print("third sensor value: ");
Serial.println(c);
if (a==1){
digitalWrite(relay,HIGH);
}
else if (b==1){
digitalWrite(relay,HIGH);
}
else{
  digitalWrite(relay,HIGH);
  }
}
