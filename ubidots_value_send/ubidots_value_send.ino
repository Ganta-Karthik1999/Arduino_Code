// This example sends data to multiple variables to
// Ubidots through HTTP protocol.

/****************************************
 * Include Libraries
 ****************************************/
#include<SoftwareSerial.h>
SoftwareSerial myserial(D2,D1);

#include "Ubidots.h"

/****************************************
 * Define Instances and Constants
 ****************************************/
String year[]={};
const char* UBIDOTS_TOKEN = "BBFF-OCER3Y1i5tOMmcESGqcgm1IGEjOyYV";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "ACT107389225313";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "82267762";      // Put here your Wi-Fi password
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

/****************************************
 * Auxiliar Functions
 ****************************************/

// Put here your auxiliar functions

/****************************************
 * Main Functions
 ****************************************/

void setup() {
  myserial.begin(9600);
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug messages
}

void loop() {
  if(Serial.available()){
    int names=Serial.read();
    Serial.println(names);
    }
//String msg="car";
//Serial.println(msg[1]);
//char first=msg[1];
////char secound=msg[2];
////char finals={first,secound};
//Serial.println(first);
//ubidots.add("RFID_DATA",first);
//bool bufferSent = false;
// bufferSent = ubidots.send("rfid_data"); // Will send data to a device label that matches the device Id
//
//  if (bufferSent) {
//    // Do something if values were sent properly
//    Serial.println("Values sent by the device");
//  }
//
//  delay(5000);
}
