//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

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
	void colision(Pared p);
	void colision(Caja c);
	int getNumero() { return numero; }
	Disparo* operator [](int i);
	void eliminar(int index);
	void eliminar(Disparo *d);
private:
	Disparo * lista[MAX_DISPAROS];
	int numero;
};