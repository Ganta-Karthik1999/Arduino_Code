#include<SoftwareSerial.h>
SoftwareSerial myserial(D2,D1);

void setup() {
myserial.begin(9600);
Serial.begin(115200);// put your setup code here, to run once:

}

void loop() {
  
String str=myserial.readStringUntil('\r');
Serial.println(str);
int str_len = str.length() + 1; 

// Prepare the character array (the buffer) 
char char_array[str_len];
// Copy it over 
str.toCharArray(char_array, str_len);
  // put your main code here, to run repeatedly:
Serial.println(str);
}
