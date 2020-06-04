//Lista de disparos, podemos ponerle un límite al personaje para que no dispare infinitamente

#pragma once

#define MAX_DISPAROS 10
#include "Disparo.h"
#include "Caja.h"

class ListaDisparos
{
public:
	ListaDisparos();
	virtual ~ListaDisparos();
	bool agregar(Disparo* d);
	void destruirContenido();
	void mueve(float t);
	void dibuja();
	void colision(Caja c);
	int getNumero() { return numero; }
	Disparo* operator [](int i);
	void eliminar(int index);
	void eliminar(Disparo *d);
	void aumentarMax() { max++; }
	void setMax(int max_disp) { max = max_disp; }
private:
	Disparo * lista[MAX_DISPAROS];
	int numero;
	int max; //Límite de disparos, aumenta consiguiendo bonus, pero nunca superará a MAX_DISPAROS
};