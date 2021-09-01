//Declaração das variáveis dos pinos digitais.

int Buzzer = 2;     // Buzzer no pino D4 (GPIO 2)
int Led = 5;        // Led no pino D1     (GPIO 5)
int SensorPIR = 4;  //Sensor no pino D2   (GPIO 4)

int valorSensor = 0;
 
void setup() {
  
  Serial.begin(115200); //Inicializando o serial monitor
 
  //Definido pinos como saídas
  
  pinMode(Buzzer,OUTPUT);
  pinMode(Led,OUTPUT);
  pinMode(SensorPIR,INPUT);
  
}
 
void loop() { 
  
  valorSensor = digitalRead(SensorPIR); // Faz a leitura do sensor 
   
  Serial.print("Valor do Sensor: "); // imprime no monitor serial 
  
  Serial.println(valorSensor); // imprime o valor do sensor no monitor.
  
  // Se o sensor detectar movimentos
  
  if (valorSensor == 1) { 
    
    // Alarme Ligado

    tone(Buzzer,1000);
    digitalWrite(Led, HIGH);

     delay(5000); // tempo de 5 segundos para desligar o Alarme
     
    noTone(Buzzer);
    digitalWrite(Led, LOW);
    
 
  } else {

  // Alarme Desligado

    noTone(Buzzer);
    digitalWrite(Led, LOW);
    
}
}
 
  
