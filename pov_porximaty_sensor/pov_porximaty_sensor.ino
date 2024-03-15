int i;
void setup() {
  Serial.begin(9600);
  pinMode(INPUT,8);// put your setup code here, to run once:

}

void loop() {

  int a=digitalRead(8);
  Serial.println(a);
  if (a==1){
    for(i=0;i<=100;i++)
    {
    Serial.println(i);
    }
    }
    else {
      Serial.println ("pov state reached");
      }
    
  // put your main code here, to run repeatedly:

}
