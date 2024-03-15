#include<LiquidCrystal.h>
int rs=7;
int e=8;
int d4=3;
int d5=4;
int d6=2;
int d7=10;
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);
void setup() {
lcd.begin(16,2);

}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Hello World");

}
