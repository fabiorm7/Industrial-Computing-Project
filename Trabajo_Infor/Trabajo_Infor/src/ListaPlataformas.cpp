#include "ListaPlataformas.h"

ListaPlataformas::ListaPlataformas()
{
	numero = 0;
	for (int i = 0; i < MAX_PLATAFORMAS; i++)
		lista[i] = 0;
}

ListaPlataformas::~ListaPlataformas()
{
}

bool ListaPlataformas::agregar(Pared * p)
{
	for (int i = 0; i < numero; i++) {
		if (lista[i] == p) {
			return false;
		}
	}
	if (numero < MAX_PLATAFORMAS)
		lista[numero++] = p;
	else
		return false;
	return true;
}

void ListaPlataformas::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaPlataformas::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

Pared * ListaPlataformas::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}
