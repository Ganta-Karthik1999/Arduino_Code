/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  Output any data on LCD widget!

  App project setup:

    LCD widget, SIMPLE mode, in widget settings :

    - Select pin V0 for zero pin
    - Select pin V1 for first pin
    - Change "Reading Frequency" to PUSH mode
    - Type into first edit field "/pin0/ seconds"
    - Type into second edit field "/pin1/ millis"
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
//#include <TimerOne.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "1f7ae6cad81047e5bc2bd48bdf21b0b1";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "TP-LINK_97B8";
char pass[] = "emtronik12";

SimpleTimer timer;


void sendSeconds() {
  Blynk.virtualWrite(V0, millis() / 1000);
}

void sendMillis() {
  Blynk.virtualWrite(V1, millis()/60000);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSeconds);
  // Setup a function to be called every second
  timer.setInterval(1000L, sendMillis);
}

void loop()
{
  Blynk.run();
  timer.run();
}

