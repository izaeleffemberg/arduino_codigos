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
 
void virarDireita(int t){ 
   
    ServoD.write(90); 
    ServoE.write(120); 
     
    delay (t);
} 
 
void virarEsquerda(int t){ 
   
    ServoD.write(60);
    ServoE.write(90); 
     
    delay(t);
}

void andarparaFrente(int t) {
 ServoD.write(0);
 ServoE.write(180); 
 
 delay (t);
}
int memLado(){
    
    boolean ladoD;
    boolean ladoE;
    Valor_Sensor1 = analogRead(Sensor1);
    Valor_Sensor2 = analogRead(Sensor2);
    
    if (Valor_Sensor1 < 100){
       
       ladoD = true;
       ladoE = false; 
     }
    if (Valor_Sensor2 < 100){
       
       ladoE = true;
       ladoD = false; 
    }
    
    if (ladoE == true) {
     return (1);
    } else return (2);
    
    
      
}


void loop(){ 
int mem;
  
Valor_Sensor1 = analogRead(Sensor1); 
Valor_Sensor2 = analogRead(Sensor2); 
 
  //while ((Valor_Sensor1 && Valor_Sensor2) > 100){ 
     
    andarparaFrente (10);
    mem = memLado();  
  //} 
   
 if((Valor_Sensor1 < 100) && (Valor_Sensor2 > 100)){ 
      virarDireita(10); 
  }else
   if((Valor_Sensor2 < 100) && (Valor_Sensor1 > 100)){ 
      virarEsquerda(10); 
  }else
   if((Valor_Sensor1 && Valor_Sensor2) < 100){
     
       if (mem == 1){
          virarDireita(10);
       } else
       virarEsquerda(10);
       
   }   

Serial.print("Sensor 1 = ");
Serial.print(Valor_Sensor1);
Serial.print(" | ");
Serial.print("Sensor 2 = ");
Serial.println(Valor_Sensor2);

    delay(10);
}   
