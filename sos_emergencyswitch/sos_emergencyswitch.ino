int button=D1;
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "-k6xCZ8LKhqxBSvwXXvcQ9yGfP--6Ul5";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "hii";
char pass[] = "";
BlynkTimer timer;
void setup() {
    Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L,sos);
pinMode(button,INPUT);

}

void loop() {
timer.run();
Blynk.run();  // put your main code here, to run repeatedly:

}

void sos(){
  
int  x=digitalRead(button);
   if (x==0){
     Blynk.notify("emergency ra pakodi");
    Blynk.email("satya.karthik1999@gmail.com","emergency ra pakodi ");
    }
    else {
      Serial.print(x);
      Serial.println("no problem");
      }
   
  
  }
