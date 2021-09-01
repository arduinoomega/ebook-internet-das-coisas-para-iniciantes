
#define BLYNK_PRINT Serial

// Bibliotecas necessárias 

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;

char auth[] = "Insira o Token"; // Aqui é necessário inserir o token enviado para o e-mail cadastrado 

char ssid[] = " Insira o Nome da rede Wi-fi utilizada";  // Insira o Nome da rede Wi-fi utilizada
char pass[] = "Insira a Senha da rede Wi-fi utilizada"; // Insira a Senha da rede Wi-fi utilizada

int flag=0;
void notificaçãoChuva()
{
  int isButtonPressed = digitalRead(16); // Faz a leitura do sensor 
  
  if (isButtonPressed==0 && flag==1) { // Se a leitura do sensor for igual a 0 (LOW), significa que está chovendo 
    
    Serial.println("Está Chovendo");
    Blynk.notify("Alerta: Começou a Chover");
    flag=0;
  }
else if (isButtonPressed==1) // se a leitura do sensor for igual a 1 (HIGH), significa que não está chovendo

  {

      flag=1;
  }
}
void setup ()
{

Serial.begin(9600);

Blynk.begin(auth, ssid, pass);

pinMode(16,INPUT); // Pino Digital D0 (GPIO16)

timer.setInterval(1000L,notificaçãoChuva); 
}
void loop ()
{
  Blynk.run ();
  timer.run ();
}
  
