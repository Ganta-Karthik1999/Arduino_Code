#include<Arduino.h>
#include<ESP8266WiFi.h>
# include<PubSubClient.h>

const char*  ssid="ACT107389225313";
const char*  pass="82267762";
const char* brokerUser="317129212056@gvpcdpgc.edu.in";
const char* brokerPass="012a9284";
const char* broker ="mqtt.dioty.co";
const char* outTopic="/317129212056@gvpcdpgc.edu.in/out";
WiFiClient espClient;
PubSubClient Client(espClient); 
long currentTime,lastTime;
int count=0;
char message[50];


void setupWifi(){
  delay(100);
  Serial.print("\n connected ");
  Serial.print(ssid);
  WiFi.begin(ssid,pass);

  while(WiFi.status()!=WL_CONNECTED){
    delay(100);
    Serial.print("...");
    
    }

  Serial.print("\n connected to");
  Serial.println(ssid);
  }

  void reconnect(){
    while(!Client.connected()){
      Serial.print("\nconnecting to ");
      Serial.println(broker);
      if(Client.connect("koikoikoi",brokerUser,brokerUser)){
        Serial.print("\n connected to");
        Serial.println(broker);
      }
      else{
        Serial.println("\n Trying connect again");
        delay(5000);
        
        }           
        
        }
      }
    
    
void setup() {
 Serial.begin(115200);
 setupWifi();
Client.setServer(broker,1883);
}

void loop() {
if (!Client.connected()){
  reconnect();
  }
Client.loop();
currentTime=millis();
if(currentTime-lastTime>2000){
  count++;
  snprintf(message,75,"%ld",count);
  Serial.println("sending message: ");
  Serial.println(message);
  Client.publish(outTopic,message);
  lastTime=millis();
  }
}
