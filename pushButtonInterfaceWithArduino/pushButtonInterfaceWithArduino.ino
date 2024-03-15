int buttonpin=12;
int x,y,z;
int X;
int red=9;
int green=10;
int blue=11;
void setup() {
Serial.begin(9600);
pinMode(12,INPUT);  
 pinMode (red,OUTPUT);
 pinMode (green,OUTPUT);
 pinMode (blue,OUTPUT);

}

void loop() {
  int X=digitalRead(buttonpin);
  Serial.println(x);
  if (X==HIGH){
    
    selectcolour(255,255,255);
    }
    else{
      
    selectcolour(0,0,0);      
    }
  }

  void selectcolour (int x,int y,int z){
  analogWrite (red,x);
analogWrite (green,y);
  analogWrite (blue,z);
 //delay(2000);
}
