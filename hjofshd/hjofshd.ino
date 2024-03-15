void setup()
{ pinMode(sensor,INPUT);
 pinMode(tpin,OUTPUT);
  pinMode(epin,INPUT);// configuring pin 7 as Input
   pinMode(13,OUTPUT);// configuring pin 6 as Input
  pinMode(buzzer,OUTPUT); // configuring pin 8 as OUTPUT
  Serial.begin(9600);
  lcd.begin(16,2);
  delay(2000);
  lcd.setCursor(2, 0);             // Set LCD cursor position (column, row)
  lcd.print("Security");                 // Print text to LCD
  lcd.setCursor(5, 1);            // Set LCD cursor position (column,row)
  lcd.print("System");                       // Print text to LCD
  delay(2000); // wait 4s                    // Delay to read text
  lcd.clear(); // clear LCD display          // Clear the display
  lcd.setCursor(2, 0);            // Set LCD cursor position (column, row)
  lcd.print("Developed By");                 // Print text to LCD
  lcd.setCursor(2, 1);            // Set LCD cursor position (column, row)
  lcd.print("Team!");              // Print text to LCD                                                                                                                                                                                                                                                                                                                                                                                                                       
delay(1000);                                 // Delay to read text
lcd.clear();                                 // Clear LCD   
lcd.setCursor(0, 0);
lcd.print("Processing Data.");
delay(1000);
lcd.clear();
lcd.setCursor(3, 0);
lcd.print("Waiting For");
lcd.setCursor(3, 1);
lcd.print("Motion....");      }
void loop()
{
Check_Burglar();
  delay(1000);// subroutine to check sensor status and activation of outputs
Check_Reset();// subroutine to check if alarm reset switch pressed or not

}
void Check_Burglar()
{{sensor_value=digitalRead(sensor); // Reading sensor value from pin 7
if(sensor_value==1) // Checking if PIR sensor sends a HIGH signal to Arduino
{ 
  
  digitalWrite(buzzer,HIGH); // Activating the buzzer
  digitalWrite(13,HIGH);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Intruder Alert!");
  digitalWrite(tpin,LOW);
  delayMicroseconds(2);
  digitalWrite(tpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(tpin,LOW);
  time1=pulseIn(epin,HIGH);
  dist=(time1*0.034)/2;
  Serial.print("dist=");
  Serial.println(dist);
  lcd.clear();
  lcd.setCursor(1,1);
  lcd.print(dist);
  
    
}}}
void Check_Reset()
{
  sensor_value=digitalRead(sensor);
if(sensor_value==0)// Checking if pushbutton was pressed
{
  digitalWrite(buzzer,LOW);
  lcd.clear();
  digitalWrite(13,LOW);// turning OFF the buzzer
  lcd.setCursor(0,1);
  lcd.print("Alarm OFF!");
}}
