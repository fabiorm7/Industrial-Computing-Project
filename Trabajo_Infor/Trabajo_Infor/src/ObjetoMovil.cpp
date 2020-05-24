//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

#include "ObjetoMovil.h"

ObjetoMovil::ObjetoMovil()
{
}


ObjetoMovil::~ObjetoMovil()
{
}

void ObjetoMovil::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
	velocidad = velocidad + aceleracion * t;
}

void ObjetoMovil::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

void ObjetoMovil::setPos(Vector2D pos)
{
	posicion = pos;
}

void ObjetoMovil::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

Vector2D ObjetoMovil::getPos()
{
	return posicion;
}

float ObjetoMovil::getRadio()
{
	return radio;
}

Vector2D ObjetoMovil::getVel()
{
	return velocidad;
}

void ObjetoMovil::setRadio(float r)
{
	radio = r;
}
