//Lista de enemigos

#include "ListaEnemigos.h"
#include "Interaccion.h"

ListaEnemigos::ListaEnemigos()
{
	numero = 0;
	for (int i = 0;i<MAX_ENEMIGOS;i++)
		lista[i] = 0;
}

ListaEnemigos::~ListaEnemigos()
{
}

bool ListaEnemigos::agregar(Enemigo * e)
{
	for (int i = 0;i < numero;i++) {
		if (lista[i] == e) {
			return false;
		}
	}
	if (numero<MAX_ENEMIGOS)
		lista[numero++] = e;
	else
		return false;
	return true;
}

void ListaEnemigos::dibuja()
{
	for (int i = 0;i<numero;i++)
		lista[i]->dibuja();
}

void ListaEnemigos::mueve(float t)
{
	for (int i = 0;i<numero;i++)
		lista[i]->mueve(t);
}

void ListaEnemigos::crear(float t)//Para crear enemigos infinitamente
{
	if (t > numero) {
		Enemigo* aux = new Enemigo(1.5, -5 + t, 12, t, 5);
		aux->setColor(t * 40, 0, 255 - t * 40);
		agregar(aux);
	}
}

void ListaEnemigos::rebote(Caja caja)
{
	for (int i = 0;i<numero;i++)
		Interaccion::rebote(*(lista[i]), caja);
}

void ListaEnemigos::rebote(Pared p)
{
	for (int i = 0;i<numero;i++)
		Interaccion::rebote(*(lista[i]), p);
}

void ListaEnemigos::rebote()
{
	for (int i = 0;i < numero;i++) {
		for (int j = 0;j < numero;j++)
			Interaccion::rebote(*(lista[i]), *(lista[j]));
	}
}

void ListaEnemigos::destruirContenido()
{
	for (int i = 0;i<numero;i++)
		delete lista[i];
	numero = 0;
}

void ListaEnemigos::eliminar(int index)
{
	if ((index<0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index;i<numero;i++)
		lista[i] = lista[i + 1];
}

void ListaEnemigos::eliminar(Enemigo *e)
{
	for (int i = 0;i<numero;i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}

Enemigo * ListaEnemigos::colision(Hombre & h)
{
	for (int i = 0;i<numero;i++)
	{
		if (Interaccion::colision(*(lista[i]), h))
			return lista[i];
	}
	return 0; //no hay colisión
}

Enemigo *ListaEnemigos::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i<0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}
