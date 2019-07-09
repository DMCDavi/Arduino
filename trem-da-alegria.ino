void setup(){
  
  pinMode(A0, INPUT);
  
  pinMode(A1, OUTPUT);
  
  pinMode(A2, OUTPUT);
  
  pinMode(A3, OUTPUT);
  
  pinMode(A4, OUTPUT);
  
  pinMode(A5, OUTPUT);
  
}

void loop(){

  int sensor, LED[5], valor = 1023/5;
  
  sensor = analogRead(A0);
  
  LED[0] = map(sensor, 0, valor, 0, 1023);

  LED[1] = map(sensor, valor, valor * 2, 0, 1023);

  LED[2] = map(sensor, valor * 2, valor * 3, 0, 1023);

  LED[3] = map(sensor, valor * 3, valor * 4, 0, 1023);

  LED[4] = map(sensor, valor * 4, valor * 5, 0, 1023);

  if(sensor <= valor){

    analogWrite(A1, LED[0]);
    
  } else{

    analogWrite(A1, 0);
    
  }   if(sensor > valor && sensor <= valor * 2){

    analogWrite(A2, LED[1]);
    
  } else{

    analogWrite(A2,0);
    
  }   if(sensor > valor * 2 && sensor <= valor * 3){

    analogWrite(A3, LED[2]);
    
  } else{

    analogWrite(A3, 0);
    
  }   if(sensor > valor * 3 && sensor <= valor * 4){

    analogWrite(A4, LED[3]);
    
  } else{

    analogWrite(A4, 0);
    
  }   if(sensor > valor * 4 && sensor <= valor * 5){

    analogWrite(A5, LED[4]);
    
  } else{

    analogWrite(A5, 0);
    
  }
  
}
