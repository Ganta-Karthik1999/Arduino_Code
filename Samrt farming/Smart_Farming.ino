#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<SoftwareSerial.h>
SoftwareSerial myserial(D1,D2);
char auth[] = "DFYk4RfbKlhl10CElBlrJQ3GSUmeG5KT";
char ssid[] = "anits";
char pass[] = "anits@123";
int finalhumidity=40;
int finaltemperature=29;

void setup() {
  
  // Debug console
  Serial.begin(115200);
myserial.begin(9600);
 Blynk.begin(auth, ssid, pass);

}


void loop() {
String msg=myserial.readStringUntil('\r'); 
Serial.println(msg);
String obstrical=msg.substring(0,1);
String watertest=msg.substring(1,2);
String humidity=msg.substring(2,4);
String temperature=msg.substring(7,9);
String soil=msg.substring(12);
//Serial.println(obstrical);
//Serial.println(watertest);
//Serial.println(humidity);
//Serial.println(temperature);



int finalobstrical=obstrical.toInt();
int finalwatertest=watertest.toInt();
int finalhumidity=humidity.toInt();
int finaltemperature=temperature.toInt();
int finalsoil=soil.toInt();

finalsoil = map(finalsoil, 0, 1023, 0, 100);

if (finalobstrical==0 or finalwatertest==0 or finalhumidity==0 or finaltemperature==0){
    
  }

  else{
if(finalobstrical==1){
  Serial.println("HUMAN ALERT!!!!");
Blynk.virtualWrite(V3,"Human Alert!!!!");
Blynk.virtualWrite(V1,finalhumidity);
Blynk.virtualWrite(V2,finaltemperature);
Blynk.virtualWrite(V4,finalsoil);
 if (finaltemperature>25 and finaltemperature<34 and finalhumidity>70 and finalhumidity<80){
    
Blynk.virtualWrite(V5,"Bactrial Blight");
Blynk.virtualWrite(V10,"Adding powered coffie grounds");
   
    }

  else if(finaltemperature>24 and finaltemperature<28 and finalhumidity>90 and finalhumidity<100){
    
Blynk.virtualWrite(V5,"Rice Blast");

Blynk.virtualWrite(V10,"Spray Mixture of Distiller water and baking soda ");
              
    
    }

    else{
      Blynk.virtualWrite(V5,"No desesace Error");
  Blynk.virtualWrite(V10,"No precaution");  
      
      } 
  
  }

 else{
  Serial.println("no human alert!!!!");
  Blynk.virtualWrite(V3,"No human detected :)");
Blynk.virtualWrite(V1,finalhumidity);
Blynk.virtualWrite(V2,finaltemperature);
Blynk.virtualWrite(V4,finalsoil);

  if (finaltemperature>25 and finaltemperature<34 and finalhumidity>70 and finalhumidity<90){
    
Blynk.virtualWrite(V5,"Bactrial Blight");
Blynk.virtualWrite(V10,"Adding powered coffie grounds");
      
    }

  else if(finaltemperature>24 and finaltemperature<28 and finalhumidity>90 and finalhumidity<100){
    
Blynk.virtualWrite(V5,"Rice Blast");
    Blynk.virtualWrite(V10,"Spray Mixture of Distiller water and baking soda ");
              
      
    
    }

    else{
      Blynk.virtualWrite(V5,"No disease alert!!!!!");
  Blynk.virtualWrite(V10,"No precaution");   
      
      }
  }    

    }


  

Serial.println(finalobstrical);
//Serial.println(finalwatertest);
//Serial.println(finalhumidity);
//Serial.println(finaltemperature);
//Serial.println(finalsoil);
Blynk.run();



}
