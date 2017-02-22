#include <Servo.h> 
 
Servo ServoD; 
Servo ServoE; 
 
int Sensor1 = 0; 
int Valor_Sensor1 = 0; 
int Sensor2 = 1; 
int Valor_Sensor2 = 0; 
 
void setup(){ 
   
  ServoD.attach(5); 
  ServoE.attach(6); 
  
Serial.begin (9600);
 
} 
 
void virarDireita(){ 
   
    ServoD.write(90); 
    ServoE.write(120); 
     
    delay(50); 
} 
 
void virarEsquerda(){ 
   
    ServoD.write(60); 
    ServoE.write(90); 
     
    delay(50); 
}

void andarparaFrente() {
 ServoD.write(0);
 ServoE.write (180); 
 
 delay (10);
}

void loop(){ 
   
Valor_Sensor1 = analogRead(Sensor1); 
Valor_Sensor2 = analogRead(Sensor2); 
 
  if((Valor_Sensor1 && Valor_Sensor2) < 100){ 
     
    andarparaFrente (10);
  } 
   
  if(Valor_Sensor1 > 100){ 
   virarEsquerda();    
  } 
   
  if(Valor_Sensor2 > 100){ 
    virarDireita(); 
  } 

Serial.print("Sensor 1 = ");
Serial.print(Valor_Sensor1);
Serial.print(" | ");
Serial.print("Sensor 2 = ");
Serial.println(Valor_Sensor2);

    delay(10);
}   


