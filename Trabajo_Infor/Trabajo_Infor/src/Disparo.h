//Disparo horizontal con personaje en movimiento y vertical si está parado

#pragma once

#include "Vector2D.h"
#include "ObjetoMovil.h"

class Disparo :public ObjetoMovil
{
public:
	Disparo(float vhombre);
	virtual ~Disparo();
	virtual void dibuja();
	friend class Interaccion;
	void setPos(Vector2D pos);
	void setPos(float x, float y);
protected:
	Vector2D origen;
};