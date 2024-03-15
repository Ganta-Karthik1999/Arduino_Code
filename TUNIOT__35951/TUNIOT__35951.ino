#include <ESP8266WiFi.h>

#include <ThingSpeak.h>

IPAddress staticIP227_10(192,168,1,10);
IPAddress gateway227_10(192,168,1,1);
IPAddress subnet227_10(255,255,255,0);

WiFiClient client;

void setup()
{
  pinMode(D0,OUTPUT);
  Serial.begin(115200);
ThingSpeak.begin(client);

  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("ACT107389225313","82267762");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");
  WiFi.config(staticIP227_10, gateway227_10, subnet227_10);
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));

}


void loop()
{

    Serial.println((ThingSpeak.readIntField(1141593,1,"YRFGLZYF2VK0QNE7")));
    int a=ThingSpeak.readIntField(1141593,1,"YRFGLZYF2VK0QNE7");
    Serial.print("the value is ");
    Serial.println(a);
   if (a==1){
    Serial.println("ligth on");
    digitalWrite(D0,HIGH);
    
    }
    else if (a==0){
    Serial.println("ligth on");
      digitalWrite(D0,LOW);
      
      }


}
