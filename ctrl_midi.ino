 #include "botoes.h"

 Botao botao(2,61,13);
  
  void setup() {  
    Serial.begin(115200); //o numero deve ser o baud configurado no hairless
    //portas
  }
  
  void loop() {  
    //rotina botao 1 
    botao.estado();

  }

    
