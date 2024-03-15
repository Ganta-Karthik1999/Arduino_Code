#include<Wire.h>

void setup(){

  Wire.begin(8);
  Serial.begin(9600);
  
}

void loop(){
  
  Wire.requestFrom(8,600);  //This function here will request the slave device 8 to send 6 bytes of data
  while(Wire.available()){
    
    char c=Wire.read();
    Serial.println(c);
    
    }
    delay(500);
  
  }
