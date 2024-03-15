#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(10, 9, 5, 4, 3, 2); 
int sensorpin=2;
void setup(){
  
  
  LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
LCD.print("HI AU STUDENTS");
  }


  void loop(){
    analogRead(sensorpin)
    
    LCD.setCursor(0,1);  //Set cursor to first column of second row
  LCD.print("                "); //Print blanks to clear the row
  LCD.setCursor(0,1);   //Set Cursor again to first column of second row
  //LCD.print("hii all"); //Print measured distance
  LCD.print(sensorpin);  //Print your units.
  delay(250); //pause
    }
