#include <IRremoteESP8266.h> // Incluido bibliotecas necessária 

int RECV_PIN = D3; // Pino Digital onde conectamos o receptor infravermelho

IRrecv irrecv(RECV_PIN); 

decode_results results; // Armazena os resultados 

void setup (){
  
  Serial.begin(9600); //Da inicio a serial
  
  irrecv.enableIRIn(); // Inicia a recepção de sinais IR
}

void loop(){
  
  //Capta o sinal IR
  
  if (irrecv.decode(&results)) {
     Serial.print ("Código DEC: "); //Texto no monitor serial
    
Serial.println (results.value); //Código em Decimal
    
    Serial.println(""); 
    irrecv.resume(); 
  }
  delay(100);
}
  
