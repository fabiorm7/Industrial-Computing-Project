//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

#pragma once

#include "Esfera.h"
#include "Caja.h"
#include "Hombre.h"

#define MAX_ESFERAS 100

class ListaEsferas {
public:
	ListaEsferas();
	virtual ~ListaEsferas();
	bool agregar(Esfera *e);
	void dibuja();
	void mueve(float t);
	void rebote(Caja caja);
	void rebote(Pared p);
	void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Esfera *e);
	Esfera* colision(Hombre &h);
	Esfera* operator [](int i);
	int getNumero() { return numero; }
private:
	Esfera * lista[MAX_ESFERAS];
	int numero;
};