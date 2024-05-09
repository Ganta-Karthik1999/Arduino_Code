#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "-k6xCZ8LKhqxBSvwXXvcQ9yGfP--6Ul5";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "hii";
char pass[] = "";
BlynkTimer timer; 
void sensordata(){
  
  int voltage=analogRead(A0);
  Serial.println(voltage);
  float temp=((3.3*voltage*100)/1023);
  
  Serial.println(temp);
  Blynk.virtualWrite(V1,temp);
if(temp>32) {
   Blynk.notify("temperatue crossed 31.29 "); 
   Blynk.tweet("temperatue crossed 31.29 ");
   Blynk.email("satya.karthik1999@gmail.com","temperatue crossed 31.29 ");
   }
  }
void setup()
{
  // Debug console
  Serial.begin(115200);
 Blynk.begin(auth, ssid, pass);
timer.setInterval(1000,sensordata);
}
void loop()
{
 timer.run();
Blynk.run();
}
