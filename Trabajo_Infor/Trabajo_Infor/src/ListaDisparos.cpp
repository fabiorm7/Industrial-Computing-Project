//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

#include "ListaDisparos.h"
#include "Interaccion.h"

ListaDisparos::ListaDisparos()
{
}

ListaDisparos::~ListaDisparos()
{
}

bool ListaDisparos::agregar(Disparo * d)
{
	for (int i = 0;i < numero;i++) {
		if (lista[i] == d) {
			return false;
		}
	}
	if (numero<MAX_DISPAROS)
		lista[numero++] = d;
	else
		return false;
	return true;
}

void ListaDisparos::destruirContenido()
{
	for (int i = 0;i<numero;i++)
		delete lista[i];
	numero = 0;
}

void ListaDisparos::mueve(float t)
{
	for (int i = 0;i<numero;i++)
		lista[i]->mueve(t);
}

void ListaDisparos::dibuja()
{
	for (int i = 0;i<numero;i++)
		lista[i]->dibuja();
}

void ListaDisparos::colision(Pared p)
{
	for (int i = 0;i<numero;i++)
	{
		if (Interaccion::colision(*(lista[i]), p))
			lista[i]->setVel(0,0);
	}
}

void ListaDisparos::colision(Caja c)
{
	for (int i = 0;i<numero;i++)
	{
		if (Interaccion::colision(*(lista[i]), c))
			eliminar(lista[i]);
	}
}

Disparo * ListaDisparos::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaDisparos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaDisparos::eliminar(Disparo * d)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == d)
		{
			eliminar(i);
			return;
		}
}
