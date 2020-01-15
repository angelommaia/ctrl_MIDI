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

  class Potenciometro{
    public:
      Potenciometro(int apin);
      void estado();
      void ativo();
    private:
      int _apin;
      int _val_novo;
      int _val_velho;
  };
#endif
