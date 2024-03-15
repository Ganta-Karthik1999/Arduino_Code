#include<Servo.h>

#include<SPI.h>

#include <RFID.h>

RFID rfid(10, 9);

const byte rled = 7;

const byte gled = 6;

const byte buzzer = 3;

boolean permission = true;

byte card[5] = {107, 135, 241, 197, 216}; /

Servo servo;

void setup(){

Serial.begin(9600);

SPI.begin();

rfid.init();

pinMode(7, OUTPUT);

pinMode(6, OUTPUT);

pinMode(3, OUTPUT);

servo.attach(5); }

void loop() {

servo.write(0);

permission = true;

if (rfid.isCard()) {

Serial.println("CARD READ");

if (rfid.readCardSerial()) {

Serial.println(" ");

Serial.println("CARD NUMBERS");

Serial.println("");

Serial.print(rfid.serNum[0]);

Serial.print(" , ");

Serial.print(rfid.serNum[1]);

Serial.print(" , ");

Serial.print(rfid.serNum[2]);

Serial.print(" , ");

Serial.print(rfid.serNum[3]);

Serial.print(" , ");

Serial.print(rfid.serNum[4]);

Serial.println(" "); }

for (int i = 0; i < 5; i++) {

if (rfid.serNum[i] != card[i])

permission = false; } }

if (permission == true) // {

Serial.println("gj");

digitalWrite(rled, LOW);

digitalWrite(buzzer, HIGH);

delay(50);

digitalWrite(buzzer, LOW);

delay(50);

digitalWrite(buzzer, HIGH);

delay(50);

digitalWrite(buzzer, LOW);

digitalWrite(gled, HIGH);

servo.write(90);

delay(2000); }

else {

Serial.println("fgh");

digitalWrite(buzzer, HIGH);

delay(300);

digitalWrite(buzzer, LOW);

digitalWrite(buzzer, HIGH);

delay(50);

digitalWrite(buzzer, LOW);

digitalWrite(buzzer, HIGH);

delay(50);

digitalWrite(buzzer, LOW);

digitalWrite(rled, HIGH);

delay(500);

digitalWrite(gled, LOW);

servo.write(0);

delay(2000); }

rfid.halt(); }

else{

digitalWrite(gled, LOW);

digitalWrite(rled, LOW);

}
