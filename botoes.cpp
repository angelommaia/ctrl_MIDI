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
    
    if (_nivel == HIGH) { 
      this->ativo();
    } 
    else{
      this->inativo();
    }
}

void Botao::ativo(){

	digitalWrite(_led, HIGH); 
	MIDI.sendNoteOn(_note,127,1); //sendNoteOn(NoteNumber, Velocity, Channel)
	delay(100);
	MIDI.sendNoteOff(_note,0,1);
	digitalWrite(_led, LOW);
	
}

void Botao::inativo(){
	digitalWrite(_led, LOW);
}