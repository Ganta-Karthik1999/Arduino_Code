#include "UbidotsMicroESP8266.h"
#define TOKEN  "BBFF-J7PJo14TCt2bEkOvLPj0M5RKoATGXy"  // Put here your Ubidots TOKEN
#define WIFISSID "ZONG MBB-E8231-6E63"
#define PASSWORD "08659650"
 
Ubidots client(TOKEN);
unsigned long lastMillis = 0;
 
int LDR = A0; 
int ldr_data = 0; 
void setup(){
    Serial.begin(115200);
    pinMode(LDR, INPUT); 
    delay(10);
    client.wifiConnection(WIFISSID, PASSWORD);
}
void loop(){
 
    if (millis() - lastMillis > 1000) {  // the ldr value is sent every 1 second. 
 
     ldr_data = analogRead(LDR); 
            lastMillis = millis();
            client.add("LDR", ldr_data);
            client.sendAll(true);
            
            }
   
}
