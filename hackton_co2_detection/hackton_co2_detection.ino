
/* Modified code by ScottyD www.youtube.com/channel/UCLx3Gi9s_5uvVwURRIsWXKg
 * 
 * Carbon Dioxide Parts Per Million Meter
 * CO2PPM
 
 * Original code by www.youtube.com/c/learnelectronics
/*
 * Atmospheric CO2 Level..............400ppm
 * Average indoor co2.............350-450ppm
 * Maxiumum acceptable co2...........1000ppm
 * Dangerous co2 levels.............>2000ppm
 */

                      //analog feed from MQ135

void setup() 
{
  pinMode(A0,INPUT);                     //MQ135 analog feed set for input
  Serial.begin(9600);                         //serial comms for debuging
}
  
void loop() 
{
//float  co2ppm=analogRead(A0);
//  Serial.print("AirQuality=");
//  Serial.print(co2ppm);  // prints the value read
//  Serial.println(" PPM");
//  delay(50);             
Serial.println("hii");
}
