#include <Servo.h>

Servo escravo;

void setup(){
  
  pinMode(10, INPUT);
  
  pinMode(11, INPUT);
  
  pinMode(12, INPUT);
  
  escravo.attach(9);
  
}

void loop(){
  
  if(digitalRead(10) == HIGH){
  	
    escravo.write(180);
    
  } else if(digitalRead(11) == HIGH){
    
  	escravo.write(90);
    
  } else if(digitalRead(12) == HIGH){
    
  	escravo.write(0);
    
  }
  
}
