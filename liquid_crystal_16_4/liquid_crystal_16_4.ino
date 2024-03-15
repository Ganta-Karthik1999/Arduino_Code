/*
https://somtips.com
https://youtube.com/somtips
*/
#include <LiquidCrystal.h>
int rs=2;//
int e=14;
int d4=16;
int d5=5;
int d6=4;
int d7=0;
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);
 void setup()
 {
   
     lcd.begin(20, 4);
  } 
     void loop()
 { 
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("Hello Karthik");
   lcd.setCursor(0, 1);
   lcd.print("how r u");
   lcd.setCursor(0, 2);
   lcd.print("i am good");
   lcd.setCursor(3, 3);
   lcd.print("thank you");
   delay(1000);
   
 }
