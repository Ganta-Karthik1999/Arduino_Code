
#include <ESP8266WiFi.h>

#include <ThingSpeak.h>

IPAddress staticIP790_10(192,168,1,10);
IPAddress gateway790_10(192,168,1,1);
IPAddress subnet790_10(255,255,255,0);

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
  WiFi.config(staticIP790_10, gateway790_10, subnet790_10);
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));

}


void loop()
{

    Serial.println((ThingSpeak.readIntField(1141593,1,"YRFGLZYF2VK0QNE7")));
   int a=ThingSpeak.readIntField(1141593,1,"YRFGLZYF2VK0QNE7");
   if (a==1){
    Serial.println("Ligth on");
    digitalWrite(D0,HIGH);
    
    }
    else if (a==0){
      Serial.println("Ligth OFF");
      digitalWrite(D0,HIGH);
      
      }

}
