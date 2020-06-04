//Lista de bonus

#pragma once

#include "Bonus.h"
#include "Caja.h"
#include "Hombre.h"

#define MAX_BONUS 100

class ListaBonus {
public:
	ListaBonus();
	virtual ~ListaBonus();
	bool agregar(Bonus *b);
	void dibuja();
	void mueve(float t);
	void rebote(Caja caja);
	void rebote(Pared p);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Bonus *e);
	Bonus* colision(Hombre &h);
	Bonus* operator [](int i);
	int getNumero() { return numero; }
private:
	Bonus * lista[MAX_BONUS];
	int numero;
};