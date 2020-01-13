
#ifndef botoes_h
#define botoes_h

#include "Arduino.h"


class Botao{

public:
	Botao(int pin, int note, int led);
	void estado();
	void ativo();
	void inativo();
private:
	int _pin;
	int _note;
	int _led;
	int _nivel=LOW;
};


#endif