#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include "DHT.h"
#define DHTPIN 4     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
int a=A0;
char auth[] = "tz2zo7NTRpI2mzu2Ct2sHEBF78MXCEhv";
char ssid[] = "project";
char pass[] = "123456789";



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(a,INPUT);
  pinMode(D0,OUTPUT);
  dht.begin();
 Blynk.begin(auth, ssid, pass);
 
}

void loop() {
 delay(2000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  int b=analogRead(a);
  Serial.println(b);
Blynk.run();
int h1 =int(h);
int t1 =int(t);
Blynk.virtualWrite(V1,h1);
Blynk.virtualWrite(V2,t1);
Blynk.virtualWrite(V3,b);
if (b<100){
  
  digitalWrite(D0,LOW);
  }

  else{
    
    digitalWrite(D0,HIGH);
    
    }


}
