//ver se tem como colocar numeros com mais de um algarismo
//fazer com que seja possivel fazer uma nova conta sem precisar resetar o arduino

#include <Keypad.h>

const byte lin = 4;

const byte col = 4;

int num1 = 10, num2 = 10, result;

char sinal;

char mat[lin][col] = {{'1', '2', '3', 'A'},
                      {'4', '5', '6', 'B'},
                      {'7', '8', '9', 'C'},
                      {'*', '0', '#', 'D'}};

byte rowPin[lin] = {11, 10, 9, 8};

byte colPin[col] = {7, 6, 5, 4};

Keypad tec = Keypad(makeKeymap(mat), rowPin, colPin, lin, col);
  
void setup(){
  
  Serial.begin(9600);

  tec.addEventListener(evento);
  
}

void loop(){
  
  tec.getKey();
  
}

void evento(KeypadEvent tecla){

  if(tec.getState() == PRESSED){

    if(tecla >= '0' && tecla <= '9'){

      if(num1 == 10){
  
        num1 = tecla - 48;
        
        Serial.print(num1);
        
      }else if(num1 != 10 && num2 == 10){
  
        num2 = tecla - 48;
          
        Serial.println(num2);
        
      }
      
    }else if(tecla == 'A'){

      sinal = '-';

      Serial.print(sinal);
      
    }else if(tecla == 'B'){

      sinal = '+';

      Serial.print(sinal);
      
    }else if(tecla == 'C'){

      sinal = '/';

      Serial.print(sinal);
      
    }else if(tecla == 'D'){

      sinal = '*';

      Serial.print(sinal);
      
    }if(tecla == '*'){

      if(sinal == '-'){

        result = num1 - num2;

        Serial.println(result);
        
      }else if(sinal == '+'){

        result = num1 + num2;

        Serial.println(result);
        
      }else if(sinal == '/'){

        result = num1 / num2;

        Serial.println(result);
        
      }else if(sinal == '*'){

        result = num1 * num2;

        Serial.println(result);
        
      }

    }
    
  }
  
}
