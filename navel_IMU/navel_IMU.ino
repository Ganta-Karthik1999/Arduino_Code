Skip to content
Why GitHub? 
Team
Enterprise
Explore 
Marketplace
Pricing 
Search

Sign in
Sign up
G6EJD
/
ESP8266_micro_compass_HMC5883_OLED
2100
Code
Issues
Pull requests
Actions
Projects
Security
Insights
Join GitHub today
GitHub is home to over 50 million developers working together to host and review code, manage projects, and build software together.

ESP8266_micro_compass_HMC5883_OLED/ESP8266_HMC5883_Compass_TN009.ino
@G6EJD
G6EJD Update ESP8266_HMC5883_Compass_TN009.ino
…
Latest commit 2ce5898 on 5 Sep 2017
 History
 1 contributor
143 lines (129 sloc)  6.11 KB
  
//
// ESP8266 micro sized compass using HMC5883 and displayed on a Wemos (64x48) OLED shield
/* This source code is protected under the terms of the MIT License and is copyright (c) 2016 by David Bird and permission is hereby granted, free of charge, to
 * any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, but not to sub-license and/or 
 * to sell copies of the Software or to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *   The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
 *   
 *   See more at http://dsbird.org.uk 
 */   
// (c) D L Bird 2016
//
#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> // SCL = GPIO5 and SDA = GPIO4
#define  OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

#define address 0x1E //0011110b, I2C 7bit address of HMC5883 which is 0x3C, base address of 0x1E is shifted left and R/W bit added

int last_dx, last_dy, dx, dy, angle;

const int centreX = 32;
const int centreY = 23;
const int radius  = 16; 

void setup(){
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.display();
  Wire.begin();
  //Put the HMC5883 IC into the correct operating mode
  Wire.beginTransmission(address); //open communication with HMC5883
  Wire.write(0x02); //select mode register
  Wire.write(0x00); //continuous measurement mode
  Wire.endTransmission();
  delay(300); // Slight delay for screen to start
  last_dx = centreX;
  last_dy = centreY;
}

void loop() {
  int16_t x,y,z; //triple axis data
  //Tell the HMC5883 where to begin reading data
  Wire.beginTransmission(address);
  Wire.write(0x03); //select register 3, X MSB register
  Wire.endTransmission();
 
 //Read data from each axis, 2 registers per axis
  Wire.requestFrom(address, 6);
  if(6<=Wire.available()){
    x = Wire.read() << 8 | Wire.read();
    z = Wire.read() << 8 | Wire.read();
    y = Wire.read() << 8 | Wire.read();
  }
  Draw_Compass_Rose(); 
  float heading = atan2(y, x); // Result is in radians
  // Now add the 'Declination Angle' for you location. Declination is the variation in magnetic field at your location.
  // Find your declination here: http://www.magnetic-declination.com/
  // At my location it is :  -2° 20' W, or -2.33 Degrees, which needs to be in radians so = -2.33 / 180 * PI = -0.041 West is + E is -
  // Make declination = 0 if you can't find your Declination value, the error is negible for nearly all locations
  float declination = -0.041;
  heading = heading + declination;
  if(heading < 0)    heading += 2*PI;  // Correct for when signs are reversed.
  if(heading > 2*PI) heading -= 2*PI;  // Correct for when heading exceeds 360-degree, especially when declination is included
  angle = int(heading * 180/M_PI); // Convert radians to degrees for more a more usual result
  // For the screen -X = up and +X = down and -Y = left and +Y = right, so does not follow coordinate conventions
  dx = (0.7*radius * cos((angle-90)*3.14/180)) + centreX;  // calculate X position for the screen coordinates - can be confusing!
  dy = (0.7*radius * sin((angle-90)*3.14/180)) + centreY;  // calculate Y position for the screen coordinates - can be confusing!
  arrow(last_dx,last_dy, centreX, centreY, 2,2,BLACK);      // Erase last arrow      
  arrow(dx,dy, centreX, centreY, 2, 2,WHITE);               // Draw arrow in new position
  last_dx = dx; 
  last_dy = dy;
  display.setCursor(0,38);
  display.fillRect(0,38,25,48,BLACK);
  display.print(angle);
  display.print(char(247)); // and the degree symbol
  display.display();
  delay(100);
}

void display_item(int x, int y, String token, int txt_colour, int txt_size) {
  display.setCursor(x, y);
  display.setTextColor(txt_colour);
  display.setTextSize(txt_size);
  display.print(token);
  display.setTextSize(1); // Back to default text size
}

void arrow(int x2, int y2, int x1, int y1, int alength, int awidth, int colour) {
  float distance;
  int dx, dy, x2o,y2o,x3,y3,x4,y4,k;
  distance = sqrt(pow((x1 - x2),2) + pow((y1 - y2), 2));
  dx = x2 + (x1 - x2) * alength / distance;
  dy = y2 + (y1 - y2) * alength / distance;
  k = awidth / alength;
  x2o = x2 - dx;
  y2o = dy - y2;
  x3 = y2o * k + dx;
  y3 = x2o * k + dy;
  x4 = dx - y2o * k;
  y4 = dy - x2o * k;
  display.drawLine(x1, y1, x2, y2, colour);
  display.drawLine(x1, y1, dx, dy, colour);
  display.drawLine(x3, y3, x4, y4, colour);
  display.drawLine(x3, y3, x2, y2, colour);
  display.drawLine(x2, y2, x4, y4, colour);
} 

void Draw_Compass_Rose() {
  int dxo, dyo, dxi, dyi;
  display.drawCircle(centreX,centreY,radius,WHITE);  // Draw compass circle
  for (float i = 0; i <360; i = i + 22.5) {
    dxo = radius * cos(i*3.14/180);
    dyo = radius * sin(i*3.14/180);
    dxi = dxo * 0.95;
    dyi = dyo * 0.95;
    display.drawLine(dxi+centreX,dyi+centreY,dxo+centreX,dyo+centreY,WHITE);   
  }
  display_item((centreX-2),(centreY-24),"N",WHITE,1);
  display_item((centreX-2),(centreY+17),"S",WHITE,1);
  display_item((centreX+19),(centreY-3),"E",WHITE,1);
  display_item((centreX-23),(centreY-3),"W",WHITE,1);
}

// Connections:
// CPU  -- Sensor
// Vin  -- Vdd
// Gnd  -- Gnd
// D1   -- SCL
// D2   -- SDA
