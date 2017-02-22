int rele = 13;

void setup() {                
  pinMode(rele, OUTPUT);
  
}

void loop() {
  
  digitalWrite(rele, HIGH);   
  delay(10000); // 10 segundos           

  digitalWrite(rele, LOW);    
  delay(30000); // 30 minuto
  
}
