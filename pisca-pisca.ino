int modo = 1;

void setup(){
  
  pinMode(13, INPUT);
  
  pinMode(12, OUTPUT);
  
  pinMode(11, OUTPUT);
  
  pinMode(10, OUTPUT);
  
}

void loop(){
  
  if(digitalRead(13) == HIGH && modo == 1){
    
    modo++;
    
  	digitalWrite(12, HIGH);
  
  	delay(6000); 
  
  	digitalWrite(12, LOW);
  
    digitalWrite(11, HIGH);
  
  	delay(2000); 
  
  	digitalWrite(11, LOW);
  
  	digitalWrite(10, HIGH);
  
  	delay(3000); 
  
  	digitalWrite(10, LOW);
    
  } 
  
  else if(digitalRead(13) == HIGH && modo == 2){
  
    modo++;
    
  	digitalWrite(11, HIGH);
  
  	delay(2000); 
  
  	digitalWrite(11, LOW);
  
  	digitalWrite(10, HIGH);
  
  	delay(3000); 
  
	digitalWrite(10, LOW);
    
  }
  
  else if(digitalRead(13) == HIGH && modo == 3){
    
  	delay(10);
    
    while(digitalRead(13) != HIGH){
      
      modo = 1;
      
      digitalWrite(11, HIGH);

      delay(500); 

      digitalWrite(11, LOW);

      delay(500);  
    
    }
      
  }
  
}
