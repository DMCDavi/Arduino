#include <Servo.h>

Servo escravo;

void setup(){
  
  pinMode(8, OUTPUT);
  
  pinMode(9, OUTPUT);
  
  pinMode(10, OUTPUT);
  
  escravo.attach(11);
  
}

void loop(){
  
  unsigned int angulo;
  
  escravo.write(0);
  
  digitalWrite(8, HIGH);
  
  delay(6000); 
  
  digitalWrite(8, LOW);
  
  for(angulo = 0; angulo <= 90; angulo++){
  	
    if(angulo <= 15 || (angulo > 30 && angulo <= 45) || (angulo > 60 && angulo <= 75)){
     
      digitalWrite(9, HIGH);
      
    }else if((angulo > 15 && angulo <= 30) || (angulo > 45 && angulo <= 60) || angulo > 75){
      
      digitalWrite(9, LOW);
      
    }
    
  	escravo.write(angulo);
    
    delay(2000/90);
  
  }
  
  digitalWrite(10, HIGH);
  
  delay(3000); 
  
  digitalWrite(10, LOW);
  
}
