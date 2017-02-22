// Izael Effemberg da Costa

// Tutorial: http://www.youtube.com/watch?v=lINWrI3DPYw
// Tutorial 2: http://ferpinheiro.wordpress.com/2011/04/29/meu-primeiro-projeto-arduino-sensor-ultrasonico-hc-sr04/

#include <Ultrasonic.h>
#define echoPin 13
#define trigPin 12
 
// funcão do ultrasonic nos pinos 12 e 13
Ultrasonic ultrasonic(12,13);
 
void setup()
{
  Serial.begin(9600); //inicia a porta serial
  pinMode(echoPin, INPUT); // seta pino como entrada
  pinMode(trigPin, OUTPUT); // seta pino saída
}
 

void loop()
{
  float tempo, distancia;  
  
  //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
  digitalWrite(trigPin, LOW);
  // delay de 2 microssegundos
  delayMicroseconds(2);
  
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
  digitalWrite(trigPin, HIGH);
  // delay de 10 microssegundos
  delayMicroseconds(10);
  //seta o pino 12 com pulso baixo novamente
  digitalWrite(trigPin, LOW);
  
  /*
  O sinal de retorno é captado, permitindo-se deduzir a distância do objeto ao sensor tomando o tempo de trânsito do sinal.
  A velocidade do sinal ultrasônico é de aproximadamente 340 m/s, assim, se o sensor estiver a uma distância "d" do objeto, 
  o sinal percorrerá uma distância equivalente a 2 vezes "d" para sair e retornar ao sensor.
  */
  
  tempo = pulseIn(echoPin, HIGH);
  distancia = (tempo/2)/29.1; // transformação da distância em CM
  
  Serial.print("Distancia em CM: ");
  Serial.println(distancia);
  delay(10);
}
