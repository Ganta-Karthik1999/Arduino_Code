#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
int rs=A0;//
int e=A1;
int d4=A2;
int d5=A3;
int d6=A4;
int d7=A5;
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);
String UID[]={"59 70 70 B3","ABSCGS","NSJSJFJNJ"};
#define SS_PIN 10
#define RST_PIN 9
#define ACCESS_DELAY 1000
#define DENIED_DELAY 1000
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
void setup() 
{
  lcd.begin(20, 4);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();          // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println();
 
}
void loop() 
{
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Welcome");
   lcd.setCursor(0,1);
   lcd.print("Mangatayaru");
   lcd.setCursor(0,2);
   lcd.print("please give Karthik");
   lcd.setCursor(0,3);
   lcd.print("His 20k");
   delay(1000);
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  Serial.print("This is");
  Serial.println(content);
int found=0;
   for(int i=0;i<2;i++){
    if (content.substring(1) ==UID[i]) // enter your own card number after copying it from serial monitor
  {
  found=found+1;
   }
 
 else   {
   
  }
   }
  if (found>=1){
    
    lcd.clear();
    delay(DENIED_DELAY);
    lcd.setCursor(0, 2);
    lcd.print("Authorized access");
     digitalWrite(2,HIGH);
    delay(ACCESS_DELAY);
    digitalWrite(2,LOW);
    
    }  
   else {
    
    lcd.clear();
    delay(DENIED_DELAY);
    lcd.setCursor(0, 3);
    Serial.println(" Access denied");
    lcd.print(" Access denied");
    digitalWrite(2,HIGH);
    delay(ACCESS_DELAY);
    delay(ACCESS_DELAY);
    digitalWrite(2,LOW);
    
    }
  
  }
  
