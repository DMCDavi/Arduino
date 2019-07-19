#include <Keypad.h>

const byte lin = 4;

const byte col = 4;

String num1, num2; 

float result;

char sinal;

char mat[lin][col] = {{'1', '2', '3', 'A'},
                      {'4', '5', '6', 'B'},
                      {'7', '8', '9', 'C'},
                      {'*', '0', '#', 'D'}};

byte rowPin[lin] = {11, 10, 9, 8};

byte colPin[col] = {7, 6, 5, 4};

bool num1_digitado = false;

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

    if(tecla >= '0' && tecla <= '9' && num1_digitado == false){
  
        num1 += tecla;
        
        Serial.print(tecla);
      
    }else if(tecla == 'A' && num1_digitado == false){

      sinal = '-';

      Serial.print(sinal);

      num1_digitado = true;
      
    }else if(tecla == 'B' && num1_digitado == false){

      sinal = '+';

      Serial.print(sinal);

      num1_digitado = true;
      
    }else if(tecla == 'C' && num1_digitado == false){

      sinal = '/';

      Serial.print(sinal);

      num1_digitado = true;
      
    }else if(tecla == 'D' && num1_digitado == false){

      sinal = '*';

      Serial.print(sinal);

      num1_digitado = true;
      
    }else if(tecla >= '0' && tecla <= '9' && num1_digitado == true){

      num2 += tecla;
        
      Serial.print(tecla);
      
    }else if(tecla == '*'){

      if(sinal == '-'){

        result = num1.toFloat() - num2.toFloat();

        Serial.println();

        Serial.print(result);

        Serial.println();
        
      }else if(sinal == '+'){

        result = num1.toFloat() + num2.toFloat();

        Serial.println();

        Serial.print(result);

        Serial.println();
        
      }else if(sinal == '/'){

        result = num1.toFloat() / num2.toFloat();

        Serial.println();

        Serial.print(result);

        Serial.println();
        
      }else if(sinal == '*'){

        result = num1.toFloat() * num2.toFloat();

        Serial.println();

        Serial.print(result);

        Serial.println();
        
      }

    }else if(tecla == '#'){

        num1 = "";
        
        num2 = ""; 

        num1_digitado = false;

        result = 0;
      
    }
    
  }
  
}
