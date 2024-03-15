

int mospin=D1;
void setup() {
  Serial.begin(9600);
  pinMode(mospin,INPUT);

}

void loop() {
  int x=digitalRead(mospin);
  Serial.println(x);
}
