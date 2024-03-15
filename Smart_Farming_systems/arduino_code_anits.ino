
#include "DHT.h"

#define DHTPIN 4     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);
int LEDpin = 7;
int obstaclePin = A0;
int hasObstacle = LOW;  // LOW MEANS NO OBSTACLE
int waterpin=3;
void setup() {
  Serial.begin(9600);
  //Serial.println(F("DHTxx test!"));

  pinMode(LEDpin, OUTPUT);
  pinMode(obstaclePin, INPUT);
  pinMode(waterpin, INPUT);
  pinMode(10,OUTPUT);  
  dht.begin();
}

void loop() {

hasObstacle = digitalRead(obstaclePin);

int waterobs = analogRead(waterpin);

  if (hasObstacle == LOW) {
   Serial.print("1"); 
    digitalWrite(LEDpin, HIGH);

  }
  else {
    Serial.print("2");
    digitalWrite(LEDpin, LOW);
  }
  if (waterobs == HIGH) {
   
    Serial.print("3");
    digitalWrite(10,HIGH);
  }
  else {
   Serial.print("4");  
  digitalWrite(10,LOW);
  }
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
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

  //Serial.print(F("Humidity: "));
  Serial.print(h);
 // Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(waterobs);
  //Serial.println(F("°C "));
  delay(2000);
}
