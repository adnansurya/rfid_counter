#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define LED_PIN 1

const char* ssid = "HOLOGRAM";
const char* password = "copastanpabatas";

String webhost = "http://192.168.1.4/rfid_counter/";
//String webhost = "http://tes.000webhostapp.com/";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, password);
 Serial.print("Connecting..");
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
     Serial.print("."); //status saat mengkoneksikan
     delay(1000);
    
  }
  Serial.println("IP_Address:"); //alamat ip lokal
    Serial.println(WiFi.localIP());

}
String dataTerima, uid;
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
       
       dataTerima = Serial.readStringUntil('\n');
       dataTerima.trim();
       Serial.println("Datanya : " + dataTerima);
       if(dataTerima.indexOf("uid:") == 0){
          uid = dataTerima.substring(4);
          Serial.println("CARD : " + uid);
         konekURL(webhost + "checkin.php?card="+ uid);
       }
   }
  
 

}


void konekURL(String url){
if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status

    WiFiClient client;
    HTTPClient http;  //Declare an object of class HTTPClient
 
     if (http.begin(client, url)) {  // HTTP


//      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
//        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
//          Serial.print("SERVER:");
          Serial.print(payload);         
          Serial.print('\n');
           delay(10);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
  }
  delay(1000);
}
