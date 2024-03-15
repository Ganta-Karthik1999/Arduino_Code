/*
  SimpleMQTTClient.ino
  The purpose of this exemple is to illustrate a simple handling of MQTT and Wifi connection.
  Once it connects successfully to a Wifi network and a MQTT broker, it subscribe to a topic and send a message to it.
  It will also send a message delayed 5 seconds later.
*/

#include "EspMQTTClient.h"

EspMQTTClient client(
  "codemania",
  "ankit03cdmn",
  "192.168.0.32",  // MQTT Broker server ip
  "MQTTUsername",   // Can be omitted if not needed
  "MQTTPassword",   // Can be omitted if not needed
  "TestClient",     // Client name that uniquely identify your device
  1883              // The MQTT port, default to 1883. this line can be omitted
);

void setup()
{
  Serial.begin(115200);

  // Optionnal functionnalities of EspMQTTClient : 
  client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  client.enableHTTPWebUpdater(); // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overrited with enableHTTPWebUpdater("user", "password").
  client.enableLastWillMessage("TestClient/lastwill", "I am going offline");  // You can activate the retain flag by setting the third parameter to true
}

// This function is called once everything is connected (Wifi and MQTT)
// WARNING : YOU MUST IMPLEMENT IT IF YOU USE EspMQTTClient
void onConnectionEstablished()
{
  // Subscribe to "mytopic/test" and display received message to Serial
  client.subscribe("test", [](const String & payload) {
    Serial.println(payload);
      strcpy[str,payload c_str()];
//    char *c=strtok(str,
//    
//    
//    ";");
//  char *c1=strtok(str,";");
 char c=strtok(str);
 char c1=strtok(str);
 
    int a= atoi(c);
    int b= atoi(c1);
//    
///  });

  // Publish a message to "mytopic/test"
 // client.publish("mytopic/test", "This is a message"); // You can activate the retain flag by setting the third parameter to true

  // Execute delayed instructions
  //client.executeDelayed(5 * 1000, []() {
   // client.publish("karthik", "This is a message sent 5 seconds later");
  });
  }

void loop()
{
  client.loop();  
}
