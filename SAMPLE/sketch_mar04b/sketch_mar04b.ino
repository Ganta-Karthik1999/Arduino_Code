

void setup() {
Serial.begin(9600);
pinMode(A1,INPUT);  // put your setup code here, to run once:

}

void loop() {
  int a=analogRead(A1);
  int b=analogRead(A0);
  Serial.println(a);
Serial.println(b);
}
