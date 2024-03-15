void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  // put your setup code here, to run once:

}

void loop() {

  int a=analogRead(A0);
  Serial.println(a);
  // put your main code here, to run repeatedly:

}
