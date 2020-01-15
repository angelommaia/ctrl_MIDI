#include "Arduino.h"
#include "botoes.h"
#include <MIDI.h>

  MIDI_CREATE_DEFAULT_INSTANCE();
  
  Botao::Botao(int pin, int note, int led){
  	pinMode(pin, INPUT);
  	pinMode(led, OUTPUT);
  	_pin=pin;
  	_note=note;
  	_led=led;
  }
  
  void Botao::estado(){	
  	_nivel = digitalRead(_pin);
    if (_nivel == HIGH) {this->ativo();} 
    else{this->inativo();}
  }
  
  void Botao::ativo(){  
  	digitalWrite(_led, HIGH); 
  	MIDI.sendNoteOn(_note,127,1); //sendNoteOn(NoteNumber, Velocity, Channel)
  	delay(1000);
  	MIDI.sendNoteOff(_note,0,1);
  	digitalWrite(_led, LOW);
  }
  
  void Botao::inativo(){
  	digitalWrite(_led, LOW);
  }

  Potenciometro::Potenciometro(int apin){
    pinMode(apin, INPUT);
    _apin=apin;
  }

 void Potenciometro::estado(){
  _val_novo=analogRead(_apin)/8; // /8 já que o range MIDI eh de 0-127
  if (_val_novo != _val_velho){this->ativo();}
 }
 
 void Potenciometro::ativo(){
  MIDI.sendControlChange(21,_val_novo,1); // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
  _val_velho = _val_novo;
  delay(100);  
 }
