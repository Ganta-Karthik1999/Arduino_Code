int x=A0;
int y=A1;
int z=A2;



void setup() {
  Serial.begin(9600);
  Serial.println("......in setup method...");
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

float xval= analogRead(x);
float yval= analogRead(y);
float zval= analogRead(z);
Serial.println(xval);
Serial.println(yval);
Serial.println(zval);
delay(2000);

}
