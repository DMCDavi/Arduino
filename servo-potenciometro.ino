#include <Servo.h>

Servo escravo;

int angulo;

void setup(){
  
  pinMode(A0, INPUT);
  
  escravo.attach(9);
  
}

void loop(){

  angulo = map(analogRead(A0),0,1023,0,180);
  
  escravo.write(angulo);
  
}
