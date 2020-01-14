#include "botoes.h"
Botao botao(2,61,13);

void setup() {  
Serial.begin(115200); //o numero deve ser o baud configurado no hairless
}

void loop() {  
botao.estado();
}

    
