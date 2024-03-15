
void colour(int x,int y,int z,int t){
analogWrite(16,x);
analogWrite(5,y);
analogWrite(4,z);
delay (t);
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(16,OUTPUT );
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);



}

void loop() {
Serial.println("printing colour ");

if (Serial.available()>0){}
Serial.println("enter");
int x=Serial.read();
int y=Serial.read();
int z=Serial.read();
Serial.println(x);
Serial.println(y);
Serial.println(z);  
 colour(x,y,z,1000);

}
