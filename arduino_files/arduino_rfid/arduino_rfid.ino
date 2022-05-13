#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#define SS_PIN 10
#define RST_PIN 9

#define JEDA_DETIK 3
#define DELAY_SERVO_MS 15

SoftwareSerial mySerial(2, 3); // RX, TX
Servo myservo;
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

String dataWifi;
int pos = 0; 

void setup() 
{
  
  Serial.begin(9600);   // Initiate a serial communication

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  mySerial.begin(9600);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

   myservo.attach(6);
      myservo.write(pos); 

}
void loop() 
{
  if(mySerial.available() > 0){
    dataWifi = mySerial.readStringUntil('\n');
//    dataWifi.trim();
    Serial.println("WIFI : " + dataWifi);
    if(dataWifi.indexOf("RES:") == 0 && dataWifi.indexOf("ERROR") == -1){
      String stat = dataWifi.substring(4); 
      Serial.println("STATUS : " + stat) ;
      if(stat == "MASUK" || stat == "KELUAR"){
        bukaPintu(JEDA_DETIK, DELAY_SERVO_MS);
      }
    }  
  }
  
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
//  Serial.print("UID tag :");
  String content= "";
  String uid = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
//     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : ":");
//     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : ":"));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
 
  content.toUpperCase();
  uid = content.substring(1);
  uid.replace(":","-");
  Serial.print("uid:");
  Serial.println(uid);
    mySerial.print("uid:");
  mySerial.println(uid);
 delay(1000);
} 



void bukaPintu(int jeda, int delayServo){
  for (pos = 0; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(delayServo);                       // waits 15ms for the servo to reach the position
  }
  delay(jeda*1000);
  for (pos = 120; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(delayServo);                       // waits 15ms for the servo to reach the position
  }  
  
}
