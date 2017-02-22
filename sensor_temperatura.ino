int SensorLuminosidade = 0;      
int valorSensor = 0; 
int led = 8;



void setup(){

  Serial.begin(9600);
  pinMode(led, OUTPUT);     

}


void loop(){
  
  
  int valorSensor = analogRead(SensorLuminosidade);
    
        if (valorSensor<=300){
        
            digitalWrite(led, HIGH);   

          
        } else {
        
            digitalWrite(led, LOW);  

        }
        
      Serial.println(valorSensor);

  delay(100); 
}
