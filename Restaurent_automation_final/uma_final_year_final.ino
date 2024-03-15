#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial (D1,D2);
char buf[]={};
int len;


const char * ssid = "ACT107389225313";
const char * password = "82267762";

String server = "http://maker.ifttt.com";
String eventName = "library management";
String IFTTT_Key = "n4sinJmUc7bDy8i_3Y4m8GeALEkvlxSneLdzRkOFmGA";
String IFTTTUrl="http://maker.ifttt.com/trigger/temp_data/with/key/e272MXJrh4_et5KUm56LmYHjJrNRtj9BjxUT5u6Njr7";


void setup() {
//  SPI.begin(); // Init SPI bus
  //rfid.PCD_Init(); // Init MFRC522
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Viola, Connected !!!");
  Serial.begin(115200);
  mySerial.begin(9600);
}


void sendDataToSheet(void)
{
  String url = server + "/trigger/" + eventName + "/with/key/" + IFTTT_Key + "?value1=" + msg;  
  Serial.println(url);
  //Start to send data to IFTTT
  HTTPClient http;
  Serial.print("[HTTP] begin...\n");
  http.begin(url); //HTTP

  Serial.print("[HTTP] GET...\n");
  // start connection and send HTTP header
  int httpCode = http.GET();
  // httpCode will be negative on error
  if(httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    // file found at server
    if(httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();

}


void loop() {

  String msg=mySerial.readStringUntil('\r');
  Serial.println(msg);
  int str_len=msg.length()+1;
  char char_array[str_len];
  msg.toCharArray(char_array,str_len);
  Serial.print(char_array[0]);
  Serial.print(char_array[1]);
  sendDataToSheet();
//int a=Serial.read();
//  Serial.println(a);
}
