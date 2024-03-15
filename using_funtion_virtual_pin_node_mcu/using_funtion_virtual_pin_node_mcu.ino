#define BLYNK_PRINT Serial //to display on serial moniter and this is already defined by blynk
  #include<ESP8266WiFi.h>
  #include<BlynkSimpleEsp8266.h>
  char auth[]="3o6EOskVZx-vR6jsOz_c-aifYVBI1BBD";
  char ssid[]="nikki";
  char pass[]="nikkichintu";
  BlynkTimer timer;//timer object syntax:BlynkTimer functionname
 
  

void setup() {
  // put your setup code here, to run once:
  Serial. begin(9600);
  Blynk.begin(auth,ssid,pass);
  timer.setInterval(1000,sensordata);                    //calling function
  
}

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();//to connect node mcu with blynk cloud
timer.run();//for continuous timer


}
void sensordata()
{
  int x=analogRead(A0);
  float t=(3.3*x*100)/1023;
  Serial.println(t);
  Blynk.virtualWrite(V1,t);
  if(t>35.48)
  {
    Blynk.notify("temperature crossed 35.48");//to get notifications
    Blynk.tweet("temperature crossed 35.48");
    Blynk.email("karthikganta55@gmail.com","temp","high");
    
  }
}
