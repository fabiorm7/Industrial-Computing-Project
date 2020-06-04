//Lista de disparos, podemos ponerle un límite al personaje para que no dispare infinitamente

#include "ListaDisparos.h"
#include "Interaccion.h"

ListaDisparos::ListaDisparos()
{
	max = 1;
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
	if (numero<MAX_DISPAROS && numero<max)
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

void ListaDisparos::colision(Pared p)//No se usa, es prescindible a no ser que queramos que el disparo se pare al tocar con una plataforma
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
