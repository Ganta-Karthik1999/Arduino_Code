
#include <Keypad.h>
#include <LiquidCrystal.h>
//#include <sr04.h>
int trigPin=10;
int echoPin=11;
int pingTravelTime;
LiquidCrystal lcd(14, 15, 16, 17, 18, 19);
char num[6];
int trigPin1 = 10;
int echoPin1 = 11;

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char keys[ROWS][COLS] = { // Matrix defining character to return for each key
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pins (R0-R3) of the keypad
byte colPins[COLS] = {4, 3, 2}; //connect to the column pins (C0-C2) of the keypad
//initialize an instance of class
char item[7];
char qt[7];
int j = 0;
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

int cost = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
  
  pinMode(13, OUTPUT);    //SR04 trig
  
  digitalWrite(13,1);
  
  lcd.begin(16, 2);  
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IoT Restaurant"); //Print blanks to clear the row
  lcd.setCursor(0, 1);
  lcd.print("with Blynk App"); //Print blanks to clear the row
  
  delay(2500);
     
}
  
void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Item No:"); //Print blanks to clear the row
  lcd.setCursor(0, 1);
  lcd.print("      Cost:"); //Print blanks to clear the row
  lcd.setCursor(12, 1);
  lcd.print(cost); //Print blanks to clear the row
 
  while(1)
  {
    char customKey = customKeypad.getKey();
    if (customKey)
    {
      item[j] = customKey;
      
      lcd.setCursor(j, 1);
      lcd.print(customKey); //Print blanks to clear the row    
      j++;        
    }
    if(j > 1)
    {
      j = 0;
      break;
    }
    
    
  }
  
 digitalWrite(trigPin,LOW);
delayMicroseconds(10);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
pingTravelTime=pulseIn(echoPin,HIGH);
delay(25);
Serial.println(pingTravelTime);
  
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Qnty:"); //Print blanks to clear the row
 
  while(1)
  {
    char customKey = customKeypad.getKey();
    if (customKey)
    {
      qt[j] = customKey;
      
      lcd.setCursor(j, 1);
      lcd.print(customKey); //Print blanks to clear the row    
      j++;        
    }
    if(j > 1)
    {
      j = 0;
      break;
    }
  }
  Serial.print("Item Number Ordered: ");
  Serial.print(item);
  Serial.print("   ");
 Serial.print("Quantity: ");
 Serial.println(qt);

  Serial.println();
  delay(2000);
    
  cost = cost + (atoi(item)*10*atoi(qt));  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Please Wait...."); //Print blanks to clear the row
  delay(3000);
  
}
