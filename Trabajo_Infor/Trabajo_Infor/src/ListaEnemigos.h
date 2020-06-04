//Lista de enemigos

#pragma once

#include "Enemigo.h"
#include "Caja.h"
#include "Hombre.h"

#define MAX_ENEMIGOS 100

class ListaEnemigos {
public:
	ListaEnemigos();
	virtual ~ListaEnemigos();
	bool agregar(Enemigo *e);
	void dibuja();
	void mueve(float t);
	void crear(float t);
	void rebote(Caja caja);
	void rebote(Pared p);
	void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Enemigo *e);
	Enemigo* colision(Hombre &h);
	Enemigo* operator [](int i);
	int getNumero() { return numero; }
private:
	Enemigo * lista[MAX_ENEMIGOS];
	int numero;
};