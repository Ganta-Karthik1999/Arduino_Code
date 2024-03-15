#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<DHT.h>
#define DHTPIN D1
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
char auth[] = "-k6xCZ8LKhqxBSvwXXvcQ9yGfP--6Ul5";
char ssid[] = "hii";
char pass[] = "";

void sensordata(){
float t=dht.readTemperature();
float h=dht.readHumidity();
Serial.println(t);
Serial.println(h);
    }



void setup() {

  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L,sensordata);

}

void loop() {
  
//float t=dht.readTemperature();// if we write it here we get the temperature and humidity values if need to update the data give it in time.setinverval()
//float h=dht.readHumidity();
//Serial.println(t);
//Serial.println(h);
timer.run();
Blynk.run();
}
