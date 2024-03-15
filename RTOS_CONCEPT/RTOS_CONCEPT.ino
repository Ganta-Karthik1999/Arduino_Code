#include<Arduino_FreeRTOS.h>


#define RED 6
#define BLUE 7
#define YELLOW 8


typedef int TaskProfiler;

TaskProfiler Rtaskprofiler;
TaskProfiler btaskprofiler;
TaskProfiler ytaskprofiler;

const uint16_t * blueLed=(uint16_t *)BLUE;
const uint16_t * redLed=(uint16_t *)RED;
const uint16_t * yellowLed=(uint16_t *)YELLOW;

TaskHandle_t BHandle,RHandle,YHandle;
int c1=0;
int c2=0;
int c3=0;
void setup(){
  
  Serial.begin(9600);
  xTaskCreate(Rledconrollertask,"RED LED control",128,(void *)redLed,1,&RHandle);
  xTaskCreate(Bledconrollertask,"BLUE LED control",128,(void *)blueLed,1,&BHandle);
  xTaskCreate(Yledconrollertask,"YELLOW LED control",128,(void *)yellowLed,1,&YHandle);
  
 }


void Rledconrollertask(void *pvParameters)
{
pinMode(6,OUTPUT);

  while(1){
    Rtaskprofiler++;
    c1++;
    digitalWrite(pvParameters,digitalRead(pvParameters)^1);
    Serial.print(c1);
    Serial.print(" This is RED led Task:  ");
    Serial.println(Rtaskprofiler);
    delay(1000);  
 
    }
     
  }


void Bledconrollertask(void *pvParameters)
{
pinMode(7,OUTPUT);

  while(1){
    btaskprofiler++;
    c2++;
    digitalWrite(pvParameters,digitalRead(pvParameters)^1);
    Serial.print(c2);
    Serial.print(" This is Blue led Task:  ");
    Serial.println(btaskprofiler);
  
  delay(1000);
    }
  
  
  }

  
void Yledconrollertask(void *pvParameters)
{
pinMode(8,OUTPUT);

  while(1){
    ytaskprofiler++;
    c3++;
    Serial.print(c3);
    digitalWrite(pvParameters,digitalRead(pvParameters)^1);
    Serial.print(" This is Yellow led Task:  ");
    Serial.println(ytaskprofiler);
  vTaskPrioritySet(BHandle,2);
  delay(1000);   
    }
   
  }


void loop(){}
