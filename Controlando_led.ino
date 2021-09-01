#include <IRremoteESP8266.h>

int const PINO_RECEPTOR = D3; // Pino Digital onde está conectado o receptor infravermelho 

int LED_VERMELHO = D0; // Pino Digital onde está conectado o LED Vermelho  
int LED_VERDE = D1;   // Pino Digital onde está conectado o LED Verde  
int LED_AZUL = D2;   // Pino Digital onde está conectado o LED Azul 

// Aqui você deve colocar os números das teclas clonadas na programação anterior

int tecla1 = 0000000000; // insira o número clonado da tecla 1
int tecla2 = 0000000000; // insira o número clonado da tecla 2
int tecla3 = 0000000000; // insira o número clonado da tecla 3
int tecla4 = 0000000000; // insira o número clonado da tecla 4
int tecla5 = 0000000000; // insira o número clonado da tecla 5
int tecla6 = 0000000000; // insira o número clonado da tecla 6
int tecla7 = 0000000000; // insira o número clonado da tecla 7
int tecla8 = 0000000000; // insira o número clonado da tecla 8

IRrecv receptor (PINO_RECEPTOR);

decode_results valorSaida;

void setup ()
{
  Serial.begin (9600);
  pinMode (LED_VERMELHO, OUTPUT); // O LED é uma Saída Digital 

   pinMode(LED_VERDE, OUTPUT);   // O LED é uma Saída Digital 
 pinMode(LED_AZUL, OUTPUT);      // O LED é uma Saída Digital 
  
  receptor.enableIRIn(); // Inicia o receptor

}

void loop () {

  if (receptor.decode(&valorSaida)) {
      receptor.resume (); // Recebe o próximo valor
   
    if (valorSaida.value == tecla1){

      // Cor Vermelha 
       
      digitalWrite (LED_VERMELHO, HIGH);  // LED Vermelho ligado
      digitalWrite (LED_VERDE, LOW);          // LED Verde desligado
      digitalWrite (LED_AZUL, LOW);             // LED Azul desligado

} else if (valorSaida.value == tecla2) {

      // Cor Verde
 
      digitalWrite (LED_VERDE, HIGH);          // LED Verde ligado
      digitalWrite (LED_VERMELHO, LOW);   // LED Vermelho desligado
      digitalWrite (LED_AZUL, LOW);              // LED Azul desligado
       
} else if (valorSaida.value == tecla3){

      // Cor Azul

      digitalWrite (LED_AZUL, HIGH);             // LED Azul ligado
      digitalWrite (LED_VERMELHO, LOW); // LED Vermelho Desligado
      digitalWrite (LED_VERDE, LOW);    // LED Verde Desligado

 } else if (valorSaida.value == tecla4){
      
      // Cor Amarela
      
      digitalWrite (LED_VERMELHO, HIGH);  // LED Vermelho ligado
      digitalWrite (LED_VERDE, HIGH);         // LED Verde ligado
      digitalWrite (LED_AZUL, LOW);           // LED Azul desligado
       
} else if (valorSaida.value == tecla5){
      
       // Lilás 
       
      digitalWrite (LED_VERMELHO, HIGH);  // LED Vermelho ligado
      digitalWrite (LED_AZUL, HIGH);             // LED Azul ligado
      digitalWrite (LED_VERDE, LOW);         // LED Verde desligado

} else if (valorSaida.value == tecla6){
       
     // Ciano 
     
      digitalWrite (LED_VERDE, HIGH);   // LED Verde ligado
      digitalWrite (LED_AZUL, HIGH);    // LED Azul ligado
      digitalWrite (LED_VERMELHO, LOW); // LED Vermelho desligado

 } else if (valorSaida.value == tecla7){
      
      // Branco
      
      digitalWrite (LED_VERDE, HIGH);          // LED Verde ligado
      digitalWrite (LED_AZUL, HIGH);             // LED Azul ligado
      digitalWrite (LED_VERMELHO, HIGH);  // LED Vermelho ligado

} else if (valorSaida.value == tecla8){
  // LED apagado
      
      digitalWrite (LED_VERDE, LOW);           // LED Vermelho desligado
      digitalWrite (LED_AZUL, LOW);              // LED Vermelho desligado
      digitalWrite( LED_VERMELHO, LOW);   // LED Vermelho desligado

      }

delay(100);

}

}
