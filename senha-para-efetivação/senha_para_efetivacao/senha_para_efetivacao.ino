#define bot1 9
#define bot2 2
#define bot3 3
#define bot4 4
#define bot5 5
#define led_verde 6
#define led_amarelo 7
#define led_vermelho 8

int cont, cont2, code[5], senha[5], ordem = 0, comp;
bool once = true, errou = false;

void setup(){
  
  for(cont = 1; cont < 6; cont++){
    
    pinMode(cont, INPUT);
    
  }pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  
  cont = 0;
  
}

void loop(){
  
  if(cont < 5){
  
    if(digitalRead(bot1) == HIGH && code[cont - 1] != 1){

      code[cont] = 1;
      cont++;

    }else if(digitalRead(bot2) == HIGH && code[cont - 1] != 2){

      code[cont] = 2;
      cont++;

    }else if(digitalRead(bot3) == HIGH && code[cont - 1] != 3){

      code[cont] = 3;
      cont++;

    }else if(digitalRead(bot4) == HIGH && code[cont - 1] != 4){

      code[cont] = 4;
      cont++;

    }else if(digitalRead(bot5) == HIGH && code[cont - 1] != 5){

      code[cont] = 5;
      cont++;

    }
    
  }if(cont == 5 && ordem < 5){
    
    if(once){
      
      digitalWrite(led_amarelo, HIGH);
      delay(200);
      digitalWrite(led_amarelo, LOW);
      delay(200);
      digitalWrite(led_amarelo, HIGH);
      delay(200);
      digitalWrite(led_amarelo, LOW);
      delay(200);
      digitalWrite(led_amarelo, HIGH);
      once = false;
      
    }if(digitalRead(bot1) == HIGH && senha[ordem - 1] != 1){
    
    senha[ordem] = 1;
    ordem++;
    
    }else if(digitalRead(bot2) == HIGH && senha[ordem - 1] != 2){

      senha[ordem] = 2;
      ordem++;

    }else if(digitalRead(bot3) == HIGH && senha[ordem - 1] != 3){

      senha[ordem] = 3;
      ordem++;

    }else if(digitalRead(bot4) == HIGH && senha[ordem - 1] != 4){

      senha[ordem] = 4;
      ordem++;

    }else if(digitalRead(bot5) == HIGH && senha[ordem - 1] != 5){

      senha[ordem] = 5;
      ordem++;

    }
   
    for(cont2 = 0, comp = 0; cont2 < 5 && ordem == 5; cont2++){
    
      if(code[cont2] == senha[cont2]){

        comp++;

      }else if(code[cont2] != senha[cont2]){
       
        errou = true;
        
      }

    }
    
  }if(comp == 5){
    
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_verde, HIGH);
    
  }else if(errou){
  
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_vermelho, HIGH);
  
  }

}
