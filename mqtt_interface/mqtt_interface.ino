/*
 Basic ESP8266 MQTT example
 This sketch demonstrates the capabilities of the pubsub library in combination
 with the ESP8266 board/library.
 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outTopic" every two seconds
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are strings not binary
  - If the first character of the topic "inTopic" is an 1, switch ON the ESP Led,
    else switch it off
 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.
 To install the ESP8266 board, (using Arduino 1.6.4+):
  - Add the following 3rd party board manager under "File -> Preferences -> Additional Boards Manager URLs":
       http://arduino.esp8266.com/stable/package_esp8266com_index.json
  - Open the "Tools -> Board -> Board Manager" and click install for the ESP8266"
  - Select your ESP8266 in "Tools -> Board"
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char* ssid = "ACT107389225313";
const char* password = "82267762";
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE  (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
//  Serial.print("Message arrived [");
//  Serial.print(topic);
//  Serial.print("] ");
  for (int i = 0; i < length; i++) {
   Serial.print((char)payload[i]);
  }  
  Serial.println();
  String data0=String((char)payload[0]);
  String data1=String((char)payload[1]);
  String data2=String((char)payload[2]);
  String data4=String((char)payload[4]);
  String data5=String((char)payload[5]);
  String data6=String((char)payload[6]);
  String data8=String((char)payload[8]);
  String data9=String((char)payload[9]);
  String data10=String((char)payload[10]);
String number=data0+data1+data2;
String number1=data4+data5+data6;
String number2=data8+data9+data10;
int x= number.toInt();
 int y= number1.toInt();
 int z= number2.toInt();

Serial.println(x);
Serial.println(y);
Serial.println(z);
 if (x==255){
  digitalWrite(16,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  }
  else if (y==255){
    
  
  digitalWrite(16,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);  
    }
 else if(z==255){
  
  digitalWrite(16,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  }
  
 }


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
   //   client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("LED");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(16, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  pinMode(5, OUTPUT);  
  pinMode(4, OUTPUT);
  digitalWrite(16,HIGH);
   digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
 
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
 client.setCallback(callback);
//  unsigned long now = millis();
//  if (now - lastMsg > 2000) {
//    lastMsg = now;
//    ++value;
//    snprintf (msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
//    Serial.print("Publish message: ");
//    Serial.println(msg);
//    client.publish("outTopic", msg);
//  }
}
