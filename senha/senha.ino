#include <Keypad.h>
#include <Password.h>

const byte lin = 4;

const byte col = 4;

Password senha = Password( "59267" );

char mat[lin][col] = {{'1', '2', '3', 'A'},
                      {'4', '5', '6', 'B'},
                      {'7', '8', '9', 'C'},
                      {'*', '0', '#', 'D'}};

byte rowPin[lin] = {11, 10, 9, 8};

byte colPin[col] = {7, 6, 5, 4};

Keypad key = Keypad(makeKeymap(mat), rowPin, colPin, lin, col);
  
void setup(){
  
  Serial.begin(9600);

  key.addEventListener(evento);
  
}

void loop(){
  
  key.getKey();
  
}

void evento(KeypadEvent tecla){

  if(key.getState() == PRESSED){

    switch (tecla){
      
      case '*': senha.evaluate(); break;
    
      case '#': senha.reset(); break;
    
      default: senha.append(tecla);
    
    }if(senha.evaluate() == true){

      Serial.print("senha certa");
      
    }
    
  }
  
}
