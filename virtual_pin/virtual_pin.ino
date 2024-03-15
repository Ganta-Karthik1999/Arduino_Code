
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "-k6xCZ8LKhqxBSvwXXvcQ9yGfP--6Ul5";
char ssid[] = "hii";
char pass[] = "";
int x;
BLYNK_WRITE(V1){
   x=param[0].asInt();
  }
void setup() {
  // Debug console
  Serial.begin(115200);
 Blynk.begin(auth, ssid, pass);
 pinMode(D0,OUTPUT);
 pinMode(D1,OUTPUT);
}

void loop() {
Blynk.run();  // put your main code here, to run repeatedly:
Serial.println(x);
if (x==1){
  digitalWrite(D0,LOW);
  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH); 
}
else{
  digitalWrite(D0,HIGH);
  digitalWrite(D1,LOW);
  digitalWrite(D2,HIGH);
  }
}
