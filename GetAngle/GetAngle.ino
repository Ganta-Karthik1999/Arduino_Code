
#include <MPU6050_tockn.h>
#include <Wire.h>
//Four LED's to show MPU6050 movement
int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
MPU6050 mpu6050(Wire);

void setup() {
  pinMode( LED1, OUTPUT);//select pins as output
  digitalWrite(LED1, LOW);
  pinMode( LED2, OUTPUT);//select pins as output
  digitalWrite(LED2, LOW);

  pinMode( LED3, OUTPUT);//select pins as output
  digitalWrite(LED3, LOW);
  pinMode( LED4, OUTPUT);//select pins as output
  digitalWrite(LED4, LOW);
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  //All LED's blink shows start getting data from MPU6050
  digitalWrite(LED1, HIGH);
  digitalWrite(LED3, HIGH);

  digitalWrite(LED2, HIGH);
  digitalWrite(LED4, HIGH);

  delay(100);
}

void loop() {
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());

  if ( ((mpu6050.getAngleY()) < -10))
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED3, HIGH);

    digitalWrite(LED2, LOW);
    digitalWrite(LED4, LOW);
  }
  else   if ( ((mpu6050.getAngleY()) > 10))
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED3, LOW);

    digitalWrite(LED2, HIGH);
    digitalWrite(LED4, HIGH);
  }
  else   if ( ((mpu6050.getAngleX()) > 10))
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);

    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  }
  else   if ( ((mpu6050.getAngleX()) < -10))
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);

    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  else   if ( ((mpu6050.getAngleZ()) > 10))
  {

    digitalWrite(LED1, HIGH);
    digitalWrite(LED4, HIGH);

    digitalWrite(LED3, LOW);
    digitalWrite(LED2, LOW);


  }
  else   if ( ((mpu6050.getAngleZ()) < -10))
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED4, LOW);

    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
  }
  else
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED3, LOW);

    digitalWrite(LED2, LOW);
    digitalWrite(LED4, LOW);
  }
}
