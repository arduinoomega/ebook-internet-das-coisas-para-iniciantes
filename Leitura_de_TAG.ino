
// Bibliotecas Necessárias 

#include <SPI.h> 
#include <MFRC522.h> 
 
#define SS_PIN D4 //Pino SDA
#define RST_PIN D3 //Pino de Reset 

MFRC522 rfid(SS_PIN, RST_PIN); 
 
void setup() {
  
  Serial.begin(9600); //Iniciando a Serial
  
  SPI.begin(); 
  rfid.PCD_Init(); 
}
 
void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) 
    return; 


  // Código Responsável por gerar a Tag
 
  
  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();

 
  Serial.print("Identificador da tag: "); //Imprime texto na Serial 
  
  Serial.println(strID); //Imprime o UID da Tag
  
  rfid.PICC_HaltA(); 
  rfid.PCD_StopCrypto1(); 
}
