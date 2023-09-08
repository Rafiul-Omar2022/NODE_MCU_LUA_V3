#define SS_PIN 5 
#define RST_PIN 0 
#include <SPI.h>
#include <MFRC522.h>

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance/object.
int variable = 0;
int LASER = 4;//d2
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  pinMode(LASER, OUTPUT);
  }
void loop() 
{
  digitalWrite(LASER, HIGH);
  // Look for new cards
  if ( mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
  {
      String content= "53 EB EC 2E" ;//" "||"another string"
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  String rfid=content.substring(1);
  Serial.println(rfid);
  delay (1000);
  }

  else{
    Serial.println("There is no RFID");
  }
}