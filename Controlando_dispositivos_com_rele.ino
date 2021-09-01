#define BLYNK_PRINT Serial

// Bibliotecas Necessárias

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "Insira o Token"; // Aqui é necessário inserir o token enviado para o e-mail cadastrado 

char ssid[] = "Insira o Nome da Rede";    // Insira o Nome da rede Wi-fi utilizada
char pass[] =  "Insira a Senha da Rede"; // Insira a Senha da rede Wi-fi utilizada

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
