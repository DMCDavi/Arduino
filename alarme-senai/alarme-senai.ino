#define echo 13
#define trig 12
#define buzzer 7
#define botao 8

int freq;
  
float tempo, CM;

void sensor(){

 digitalWrite(trig, LOW);

  delayMicroseconds(2);

  digitalWrite(trig, HIGH);

  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  delayMicroseconds(2);

  tempo = pulseIn(echo, HIGH); //1 cm ----- 29.1 microsegundos
  
  CM = (tempo/2) /29.1;
  
}

void setup(){
  
  pinMode(botao, INPUT);
  
  pinMode(echo, INPUT);
  
  pinMode(trig, OUTPUT);
  
  pinMode(buzzer, OUTPUT);

}

void loop(){

  sensor();

  if (CM <= 20 && CM != 0){

    while(digitalRead(botao) != HIGH){
    
      for(freq = 1440; freq <= 1880; freq++){

        sensor();
        
        tone(buzzer, freq);

        delay(3000/440);

        if(digitalRead(botao) == HIGH){

          break;
          
        }

      }for(freq = 1880; freq >= 1440; freq--){

        sensor();

        tone(buzzer, freq);

        delay(3000/440);

        if(digitalRead(botao) == HIGH){

          break;
          
        }

      }

    }
  
}else{
 
    noTone(buzzer);
  
  }
    
}
  
