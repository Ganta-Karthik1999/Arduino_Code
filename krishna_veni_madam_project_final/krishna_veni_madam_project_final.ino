/*D4----SDA
  D5----SCK
  D7----MOSI
  D6----MISO
NOT CONNECTED----IRQ
 GND----GND
  D8-----RST
  3V-----3.3V
*/
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SPI.h>
#include <MFRC522.h>

constexpr uint8_t RST_PIN = D8;  // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = D4;  // Configurable, see typical pin layout above

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;
String tag;

const char * ssid = "ACT107389225313";
const char * password = "82267762";

String server = "http://maker.ifttt.com";
String eventName = "library management";
String IFTTT_Key = "n4sinJmUc7bDy8i_3Y4m8GeALEkvlxSneLdzRkOFmGA";
String IFTTTUrl="http://maker.ifttt.com/trigger/temp_data/with/key/e272MXJrh4_et5KUm56LmYHjJrNRtj9BjxUT5u6Njr7";

String value1;
String value2;
String value3;
String names[]={"karthik","Ganesh"};
String roll[]={"317129212056","317129212058"};
String branch[]={"ECE","CSE"};
String s[]={"8919765179","73102188162"};

void setup() {
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Viola, Connected !!!");
}


void sendDataToSheet(void)
{
  String url = server + "/trigger/" + eventName + "/with/key/" + IFTTT_Key + "?value1=" + value1 + "&value2="+ value2 +"&value3=" + value3;  
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
  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if (rfid.PICC_ReadCardSerial()) {
    for (byte i = 0; i < 4; i++) {
      tag += rfid.uid.uidByte[i];
    }
 for(int i=0;i<2;i++){
      
if (tag==s[i]){
  
  value1=roll[i];
  value2 = names[i];
  value3 = branch[i];
  sendDataToSheet();
  Serial.println("Autherized Axcess");
  }

  else{
    
    Serial.println("Axcess Denied");
    }
      }
    Serial.println(tag);
    tag = "";
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
}
