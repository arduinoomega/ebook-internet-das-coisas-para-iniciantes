#define BLYNK_PRINT Serial

// Bibliotecas necessárias 

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "Insira o Token"; // Aqui é necessário inserir o token enviado para o e-mail cadastrado 

char ssid[] = "Insira o Nome da rede Wi-fi utilizada";  // Insira o Nome da rede Wi-fi utilizada
char pass[] = "Insira a Senha da rede Wi-fi utilizada"; // Insira a Senha da rede Wi-fi utilizada



int PinoAnalogico = A0; // Define o pino A0 como Pino Analógico do sensor
int PinoDigital = D2; // Define pino D2 como Pino Digital do Sensor 

int Rele = D1; // Pino Digital D1 como Relé

int EstadoSensor = 0;
int UltimoEstSensor = 0;



int  ValAnalogIn; // Introduz o valor analógico ao código

void setup() {
Serial.begin(9600); 
Blynk.begin(auth, ssid, pass);

pinMode(Rele, OUTPUT); // Declara o Rele como Saída Digital 
pinMode(PinoDigital, INPUT);

}

void loop() {

// Programação da Notificação 

  Blynk.run();

  EstadoSensor = digitalRead(PinoDigital);

if (EstadoSensor == 1 &&  UltimoEstSensor == 0) {
  
  Blynk.notify("Umidade Baixa: Irrigando a Planta");
  UltimoEstSensor = 1;
  delay(1000);

    
  } 
  else if (EstadoSensor == 1 &&  UltimoEstSensor == 1) {
  delay(1000);
  }
  else {
  
     UltimoEstSensor = 0;
    delay(1000);
  }

// Fim da Programação da Notificação 

ValAnalogIn = analogRead(PinoAnalogico);
int Porcento = map(ValAnalogIn, 1023, 0, 0, 100); // Traforma o valor analógico em porcentagem

Serial.print("Umidade: "); // Imprime o símbolo no valor
Serial.print(Porcento); // Imprime o valor em Porcentagem no monitor Serial
Serial.println("%");
 


if (Porcento <= 76) { // Se a porcentagem for menor ou igual à 76%. OBS: Você pode alterar essa porcentagem 
  
Serial.println("Irrigando Planta"); // Imprime no monitor serial
digitalWrite(Rele, LOW); // Aciona Relé
}

else { // Caso contrario 
  
Serial.println("Planta Irrigada"); // Imprime a  no monitor serial
digitalWrite(Rele, HIGH); // Desliga Relé
delay (1000);
}
}
