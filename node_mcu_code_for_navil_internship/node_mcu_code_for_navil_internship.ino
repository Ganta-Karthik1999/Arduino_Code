
/*
 * lcd.print(x,y,"messsage"); 
 * where x is a symbol position(0 to 15)
 * y is a line number (0 or 1)
 * lcd.clear();
 */
 
#define BLYNK_PRINT Serial
 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
 
WidgetLCD lcd(V2);
String data = ""; // this will be used to store the value of the variable resistor. the value will be converted into string as the lcd widget accept data in string format.
int clflag = 0; // clear lcd flag. 
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "34e8cf4e86d94629a0e3f6ca4f3d0d5d";
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ZONG MBB-E8231-6E63";
char pass[] = "08659650";
 
SimpleTimer timer;
 
// sensors 
int vr = A0; // variable resistor connected 
 
int sdata = 0; // sensor data will be stored in this variable.
 
// This function sends Arduino's up time every second to Virtual Pin (1).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, millis() / 1000);
 
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(vr ,INPUT); 
  Blynk.begin(auth, ssid, pass);
 
  // Setup a function to be called every second
  timer.setInterval(1000L,sensorvalue); 
}
 
void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
 
}
 
