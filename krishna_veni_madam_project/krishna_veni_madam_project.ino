#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
int rs=A0;//
int e=A1;
int d4=A2;
int d5=A3;
int d6=A4;
int d7=A5;
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);
String UID[]={"59 C5 41 B3","ABSCGS","NSJSJFJNJ"};
String year[]={"17","18","19"};
String branch[]={"20","00","01"};
String rollnumber[]={"56","57","58"}; 
#define SS_PIN 5
#define RST_PIN 9
#define RELAY 3 //connect the relay to number 3 pin
#define BUZZER 2 // connect the buzzer to 2 pin
#define ACCESS_DELAY 2000
#define DENIED_DELAY 1000
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
void setup() 
{
  SoftwareSerial espSerial(0, 1);
espSerial.begin(115200);
  lcd.begin(16, 2);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();          // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  pinMode(RELAY, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  digitalWrite(RELAY, HIGH);
  //Serial.println("Put your card to the reader for scanning ...");
  Serial.println();

}
void loop() 
{int a=10;
  Serial.print(a);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Welcome");
   lcd.setCursor(0,1);
   lcd.print("Mangatayaru");
   lcd.setCursor(0,2);
   lcd.print("please give Karthik");
  // Look for new cards
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
  //Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
    // Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     //Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println();
  
int found=0;
   for(int i=0;i<2;i++){
    if (content.substring(1) ==UID[i]) // enter your own card number after copying it from serial monitor
  {
    //String value[]={year[i]+branch[i]+rollnumber[i]};
    //Serial.println(value[0]); 
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
