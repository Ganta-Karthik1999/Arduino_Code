#include<Wire.h>

int temp_address=72;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  

}

void loop() {

  Wire.beginTransmission(temp_address);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(temp_address,1);

  while(Wire.available()==0);

Wire.onReceive(1);

  int f= round(2.56);
  Serial.print(f);
  delay(500);
  
  

}
