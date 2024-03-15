
void setup() {
Serial.begin(9600);  // put your setup code here, to run once:
pinMode(3,INPUT);
}


void loop() {
int a=digitalRead(3); 
Serial.println(a);  
if(a==1){
  Serial.println("button not pressed ");
 }
else{
  Serial.println("butten press chesavu");
  }
}
