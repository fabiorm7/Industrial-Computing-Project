//Lista de plataformas para mejorar su manejo y creación

#pragma once

#include "Pared.h"
#include "ObjetoMovil.h"

#define MAX_PLATAFORMAS 6

class ListaPlataformas {
public:
	ListaPlataformas();
	virtual ~ListaPlataformas();
	bool agregar(Pared *p);
	void dibuja();
	void destruirContenido();
	Pared* operator [](int i);
	int getNumero() { return numero; }
private:
	Pared * lista[MAX_PLATAFORMAS];
	int numero;
};