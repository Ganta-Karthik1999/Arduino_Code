#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include<DHT.h>
#define DHTPIN D1
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

WiFiClient client;

String thingSpeakAddress= "http://api.thingspeak.com/update.json?";
String request_string;

HTTPClient http;

void setup()
{
    Serial.begin(9600);
    dht.begin();
    WiFi.disconnect();
   WiFi.begin("nikki","nikkichintu");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);

  }

}


void loop()
{
float t=dht.readTemperature();
  float h=dht.readHumidity();
    if (client.connect("api.thingspeak.com",80)) {
      request_string = thingSpeakAddress;
      request_string += "api_key=";
      request_string += "6QKNETFNDVTSQAIJ";
      request_string += "&";
      request_string += "field4";
      request_string += "=";
      request_string += analogRead(A0);
      request_string +="&field1";
      request_string += "=";
      request_string +=t;
      request_string += "&field2";
      request_string += "=";
      request_string += h;
      http.begin(request_string);
      http.GET();
      http.end();
      Serial.println(request_string);
    }



    }
